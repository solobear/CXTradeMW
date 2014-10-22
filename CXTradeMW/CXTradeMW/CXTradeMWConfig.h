#include "stdafx.h"

#define PLEN 64

class CXTradeMWConfig
{

private:
	int logLevel;

	char serverIP[PLEN];
	int serverPort;

	char appCode[PLEN];
	char vendorID[PLEN];
	char vendorPassword[PLEN];

	static CXTradeMWConfig *m_pInstance;
	CXTradeMWConfig();   //构造函数是私有的

public:
	static CXTradeMWConfig* Instance();

	int LogLevel();//LogLevel

	char* ServerIP();//IP
	int ServerPort();//Port

	char* AppCode();//APPCode
	char* VendorID();//Vendor ID
	char* VendorPassword();//Vendor Password

};