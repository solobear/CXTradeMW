
// CXTradeMWDlg.h : 头文件
//

#pragma once
#include "CXTradeMWSocketListener.h"


// CCXTradeMWDlg 对话框
class CCXTradeMWDlg : public CDialogEx
{
	// 构造
public:
	CCXTradeMWDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_CXTRADEMW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

public:
	int port;
	CXMWSocketListener m_srvrSocket;

	virtual void Start();

	afx_msg void OnBnClickedBnStart();
	afx_msg void OnBnClickedBnExit();
};
