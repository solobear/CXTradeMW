
// CXTradeMWDlg.h : ͷ�ļ�
//

#pragma once
#include "CXTradeMWSocketListener.h"


// CCXTradeMWDlg �Ի���
class CCXTradeMWDlg : public CDialogEx
{
	// ����
public:
	CCXTradeMWDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_CXTRADEMW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
