// TestCXTradeApi.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "api/TradeApi.h"
#include "MyTradeSpi.h"
#include <iostream>
#include "windows.h"
using namespace std;


HANDLE g_hEvent;

void ShowTraderCommand(CMyTradeSpi* p, bool print=false){
	if(print){
		cerr<<"-----------------------------------------------"<<endl;
		cerr<<" [1] ReqUserLogin              -- ��¼"<<endl;
		cerr<<" [2] ReqOpenMarketOrder        -- �м۵�����"<<endl;
		cerr<<" [3] ReqCloseMarketOrder		  -- �м۵�ƽ��"<<endl;
		cerr<<" [4] ReqOpenLimitOrder		  -- �޼۵�����"<<endl;
		cerr<<" [5] ReqLimitClosePosition     -- �޼۵�ƽ��"<<endl;
		cerr<<" [6] ReqLimitRevoke            -- �޼۵�����"<<endl;
		cerr<<" [7] ReqQryAccountInfo         -- ��ѯ�˻���Ϣ"<<endl;
		cerr<<" [8] ReqQryCommodity           -- �����ѯ��Ʒ��Ϣ"<<endl;
		cerr<<" [9] ReqQryPositionOrder       -- �����ѯ�ֲֵ���Ϣ"<<endl;
		cerr<<" [10] ReqQryLimitOrder		  -- �����ѯ�޼۵���Ϣ"<<endl;
		cerr<<" [11] ReqQryClosePosition	  -- �����ѯƽ�ֵ���Ϣ"<<endl;
		cerr<<" [12] ReqQryHoldPositionTotal  -- �����ѯ�ֲֵ�����"<<endl;
		cerr<<" [13] ReqQryMarketStatus		  -- �����ѯ�г�״̬"<<endl;
		cerr<<" [14] ��ʾ�г�����"<<endl;
		cerr<<" [15] ȡ����ʾ�г�����"<<endl;
		cerr<<" [0] Exit                      -- �˳�"<<endl;
		cerr<<"----------------------------------------------"<<endl;
	}   

	int cmd;  cin>>cmd;
	switch(cmd){
	case 1: {
		p->ReqUserLogin("003098765432103", "123456"); break;
			}
	case 2: {
		CXOpenMarketOrderParam mOrder;
		mOrder.nCommodityID = 100001;
		mOrder.nOrderType = 1;
		mOrder.nOpenDirector = CX_OPENDIRECTOR_BUY;
		mOrder.nQuantity = 5;
		mOrder.dbTradeRange = 50;
		mOrder.dbPrice = 3.760;
		p->ReqOpenMarketOrder(&mOrder); break;
			}
	case 3: {
		int nHoldPositionID = 0;
		int nCommodityID = 0;
		int nQuantity = 0;
		int nTradeRange = 0;
		double dbPrice = 0;
		cerr<<" �ֲ�ID > "; cin>>nHoldPositionID; 
		cerr<<" ��ƷID > "; cin>>nCommodityID; 
		cerr<<" ƽ������ > "; cin>>nQuantity; 
		cerr<<" ���׷�Χ ����ĵ�Χ > "; cin>>nTradeRange; 
		cerr<<" ƽ�ּ۸� > "; cin>>dbPrice; 
		CXCloseMarketOrderParam mCloseOrder;
		mCloseOrder.nHoldPositionID = nHoldPositionID;			///< �ֲ�ID
		mCloseOrder.nCommodityID = nCommodityID;				///< ��ƷID
		mCloseOrder.nQuantity = nQuantity;						///< ƽ������
		mCloseOrder.nTradeRange = nTradeRange;					///< ���׷�Χ
		mCloseOrder.dbPrice = dbPrice;							///< ƽ�ּ۸�
		mCloseOrder.nClosePositionType = 1;						///< ƽ������ ��1
		p->ReqCloseMarketOrder(&mCloseOrder); 
		break;
			} 
	case 4: {
		CXOpenLimitOrderParam lOrder;
		lOrder.nCommodityID = 100001;
		lOrder.dbOrderPrice = 3.410;
		lOrder.nOpenDirector = CX_OPENDIRECTOR_BUY;
		lOrder.nOrderType = 1;
		lOrder.dbSLPrice = 3.200;
		lOrder.dbTPPrice = 3.700;
		lOrder.nExpireType = 1;
		lOrder.nQuantity = 5;
		p->ReqOpenLimitOrder(&lOrder);
		break;
			}
	case 5: {
		int nCommodityID = 0;
		double dbClosePrice = 0;
		int nExpireType = 0;
		long long nHoldPositionID = 0;
		int nOrderType = 0;
		int nQuantity = 0;
		double dbSLPrice = 0;
		double dbTPPrice = 0;
		cerr<<" ��ƷID > "; cin>>nCommodityID; 
		cerr<<" ƽ�ֵ��� > "; cin>>dbClosePrice; 
		cerr<<" �������� > "; cin>>nExpireType;
		cerr<<" �ֲ�ID > "; cin>>nHoldPositionID;
		cerr<<" �µ����� > "; cin>>nOrderType;      
		cerr<<" ƽ������ > "; cin>>nQuantity;   
		cerr<<" ֹӯ�۸� > "; cin>>dbSLPrice;   
		cerr<<" ֹ��۸� > "; cin>>dbTPPrice;   
		CXCloseLimitOrderParam lCloseOrder;
		lCloseOrder.nCommodityID = nCommodityID;			///< ��ƷID
		lCloseOrder.dbClosePrice = dbClosePrice;		///< ƽ�ֵ���
		lCloseOrder.nExpireType = nExpireType;			///< ��������
		lCloseOrder.nHoldPositionID = nHoldPositionID;	///< �ֲ�ID
		lCloseOrder.nOrderType = nOrderType;				///< �µ�����
		lCloseOrder.nQuantity = nQuantity;				///< ƽ������
		lCloseOrder.dbSLPrice = dbSLPrice;			///< ֹӯ�۸�
		lCloseOrder.dbTPPrice = dbTPPrice;			///< ֹ��۸�
		p->ReqLimitClosePosition(&lCloseOrder); 
		break;
			}
	case 6: { 
		long long nLimitOrderID = 0;
		int nCommodityID = 0;
		int nOrderType = 0;
		int nLimitType = 0;
		cerr<<" �޼۵�ID > "; cin>>nLimitOrderID; 
		cerr<<" ��ƷID > "; cin>>nCommodityID; 
		cerr<<" �µ����� > "; cin>>nOrderType;
		cerr<<" �޼۵����� > "; cin>>nLimitType;
		CXLimitRevokeParam limitRevoke;
		limitRevoke.nLimitOrderID = nLimitOrderID;	///< �޼۵�ID
		limitRevoke.nCommodityID = nCommodityID;			///< ��ƷID
		limitRevoke.nOrderType = nOrderType;				///< �µ�����
		limitRevoke.nLimitType = nLimitType;				///< �޼۵�����
		p->ReqLimitRevoke(&limitRevoke);break;
			}
	case 7: p->ReqQryAccountInfo();break;
	case 8: p->ReqQryCommodity();break;
	case 9: p->ReqQryPositionOrder();break;
	case 10: p->ReqQryLimitOrder();break;
	case 11: p->ReqQryClosePosition();break;
	case 12: p->ReqQryHoldPositionTotal();break;
	case 13: p->ReqQryMarketStatus();break;
	case 14: p->SetObMD(true);break;
	case 15: p->SetObMD(false);break;
	case 0: exit(0);
	}  
	WaitForSingleObject(g_hEvent,INFINITE);
	ResetEvent(g_hEvent);
	ShowTraderCommand(p);
}

int main(int argc, char* argv[])
{
	try{
		CTradeApi *pApi = CTradeApi::CreateTradeApi(".\\log\\");
		pApi->RegisterFront("183.62.250.18", 9745);
		pApi->SetAppMessage("test1", "123456", "874987497234");
		CMyTradeSpi *spi = new CMyTradeSpi(pApi);
		pApi->RegisterSpi(spi);
		int n = pApi->Init();
		if (n)
		{
			printf("error !");
			return -1;
		}
		//pApi->ReqUserLogin("003098765432103", "123456");
		ShowTraderCommand(spi, true);

		pApi->Join();
	}
	catch (std::exception &e){
		cout << e.what();
		Sleep(20000);
	}
	return 0;
}

