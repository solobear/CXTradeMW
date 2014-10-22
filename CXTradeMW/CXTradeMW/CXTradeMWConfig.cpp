#include "stdafx.h"
#include "CXTradeMWConfig.h"
#include <iostream>
#include "log4z.h"

using namespace zsummer::log4z;
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

	// LOG Level
	logLevel = ILog4zManager::GetInstance()->GetLoggerLevel(LOG4Z_MAIN_LOGGER_ID);
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


// Log Level
int CXTradeMWConfig::LogLevel(){
	return logLevel;
}