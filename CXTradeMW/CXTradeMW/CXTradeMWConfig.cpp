#include "stdafx.h"
#include "CXTradeMWConfig.h"
#include <iostream>

using namespace std;

CXTradeMWConfig* CXTradeMWConfig::m_pInstance = NULL;

CXTradeMWConfig::CXTradeMWConfig()   //构造函数是私有的
{
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy_s(lpPath, MAX_PATH, "./CXTradeMW.ini");

	// Server
	GetPrivateProfileString("Server", "ServerIP", "", serverIP, PLEN, lpPath);
	serverPort = GetPrivateProfileInt("Server", "Port", 0, lpPath);

	// App
	GetPrivateProfileString("APP", "AppCode", "", appCode, PLEN, lpPath);
	GetPrivateProfileString("APP", "VendorID", "", vendorID, PLEN, lpPath);
	GetPrivateProfileString("APP", "VendorPassword", "", vendorPassword, PLEN, lpPath);
	delete[] lpPath;
}

///
CXTradeMWConfig* CXTradeMWConfig::Instance()
{
	if (m_pInstance == NULL)  //判断是否第一次调用
		m_pInstance = new CXTradeMWConfig();
	return m_pInstance;
}

// IP
char* CXTradeMWConfig::ServerIP(){
	return serverIP;
}

// Port
int CXTradeMWConfig::ServerPort(){
	return serverPort;
}

// AppCode
char* CXTradeMWConfig::AppCode(){
	return appCode;
}

// VendorID
char* CXTradeMWConfig::VendorID(){
	return vendorID;
}

// Vendor Pass
char* CXTradeMWConfig::VendorPassword(){
	return vendorPassword;
}