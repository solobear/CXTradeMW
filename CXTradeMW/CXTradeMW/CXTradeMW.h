
// CXTradeMW.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCXTradeMWApp: 
// �йش����ʵ�֣������ CXTradeMW.cpp
//

class CCXTradeMWApp : public CWinApp
{
public:
	CCXTradeMWApp();

	// ��д
public:
	virtual BOOL InitInstance();

	// ʵ��
	virtual void InitConsole();

	DECLARE_MESSAGE_MAP()
};

extern CCXTradeMWApp theApp;