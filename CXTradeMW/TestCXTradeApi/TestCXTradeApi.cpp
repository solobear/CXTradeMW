#include <windows.h>
#include <iostream>
#include "api/TradeApi.h"
#include "MyTradeSpi.h"
using namespace std;


DWORD WINAPI ThreadMethod(LPVOID lpParameter);

CTradeApi* pApi;
CTradeSpi* pSpi;

int main(int argc, char* argv[])
{
	HANDLE hThread = NULL;
	DWORD dwThreadID = 0;
	hThread = CreateThread(0, 0, ThreadMethod, NULL, 0, &dwThreadID);//创建线程

	Sleep(10000);
	pApi->ReqQryMarketStatus();
	pApi->ReqQryAccountInfo();

	Sleep(15000);

	pApi->Release();
	
	system("pause");
	return 0;
}


DWORD WINAPI ThreadMethod(LPVOID lpParameter)
{
	pApi = CTradeApi::CreateTradeApi("./log/");
	pSpi = new CMyTradeSpi(pApi);
	
	pApi->RegisterSpi(pSpi);

	pApi->RegisterFront("183.62.250.18", 9745);
	pApi->SetAppMessage("test1", "123456", "874987497234");

	int res = pApi->Init();
	if (res)
	{
		printf("Error: %d", res);
		return -1;
	}
	printf("Login...\n");
	pApi->ReqUserLogin("003098765432103", "123456");

	pApi->Join();
	return 0;
}
