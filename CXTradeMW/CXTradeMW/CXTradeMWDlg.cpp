
// CXTradeMWDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CXTradeMW.h"
#include "CXTradeMWDlg.h"
#include "afxdialogex.h"
#include "log4z.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace zsummer::log4z;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCXTradeMWDlg 对话框



CCXTradeMWDlg::CCXTradeMWDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCXTradeMWDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCXTradeMWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCXTradeMWDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BN_START, &CCXTradeMWDlg::OnBnClickedBnStart)
	ON_BN_CLICKED(IDCANCEL, &CCXTradeMWDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()


// CCXTradeMWDlg 消息处理程序

BOOL CCXTradeMWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	ILog4zManager::GetInstance()->Config("Log4Z.cfg");
	ILog4zManager::GetInstance()->Start(); // 初始化Log4z
	Start();                               // 直接启动中间件

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCXTradeMWDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCXTradeMWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCXTradeMWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCXTradeMWDlg::OnBnClickedBnStart()
{
	Start();
}

void CCXTradeMWDlg::OnBnClickedBnExit()
{
	UINT nRet = MessageBox("确定退出交易中间件？", "提示", MB_OKCANCEL);

	if (nRet == IDOK)
	{
		// 停止socket
		if (m_srvrSocket != INVALID_SOCKET)
		{
			LOGI("停止Socket服务");
			m_srvrSocket.Close();
		}

		// 确定退出
		CDialogEx::OnCancel();
	}
}


/// 启动中间件
void CCXTradeMWDlg::Start()
{
	port = 7190;
	if (m_srvrSocket.m_hSocket == INVALID_SOCKET)
	{
		LOGI("");
		LOGI("");
		LOGI("启动交易中间件，侦听端口: " << port);
		LOGI("");
		LOGI("");

		//创建监听套接字,激发FD_ACCEPT事件
		BOOL bFlag = m_srvrSocket.Create(port, SOCK_STREAM, FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
		if (!bFlag)
		{
			AfxMessageBox(_T("Socket创建失败!"));
			m_srvrSocket.Close();
			PostQuitMessage(0);

			return;
		}

		// 禁用再次启动按钮
		GetDlgItem(IDC_BN_START)->EnableWindow(FALSE);

		//监听成功,等待连接请求
		if (!m_srvrSocket.Listen())//如果监听失败
		{
			int nErrorCode = m_srvrSocket.GetLastError();	//检测错误信息
			if (nErrorCode != WSAEWOULDBLOCK)				//如果不是线程阻塞
			{
				AfxMessageBox(_T("Socket错误!"));
				m_srvrSocket.Close();
				PostQuitMessage(0);

				return;
			}
		}
	}
}




