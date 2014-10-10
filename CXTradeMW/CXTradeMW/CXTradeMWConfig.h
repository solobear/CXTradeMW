#include "stdafx.h"

#define PLEN 64

class CXTradeMWConfig
{

private:
	char serverIP[PLEN];
	int serverPort;

	char appCode[PLEN];
	char vendorID[PLEN];
	char vendorPassword[PLEN];

	static CXTradeMWConfig *m_pInstance;
	CXTradeMWConfig();   //���캯����˽�е�

public:
	static CXTradeMWConfig* Instance();

	char* ServerIP();//IP
	int ServerPort();//Port

	char* AppCode();//APPCode
	char* VendorID();//Vendor ID
	char* VendorPassword();//Vendor Password

};