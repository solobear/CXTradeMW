// TestCXTradeApi.cpp : 定义控制台应用程序的入口点。
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
		cerr<<" [1] ReqUserLogin              -- 登录"<<endl;
		cerr<<" [2] ReqOpenMarketOrder        -- 市价单开仓"<<endl;
		cerr<<" [3] ReqCloseMarketOrder		  -- 市价单平仓"<<endl;
		cerr<<" [4] ReqOpenLimitOrder		  -- 限价单开仓"<<endl;
		cerr<<" [5] ReqLimitClosePosition     -- 限价单平仓"<<endl;
		cerr<<" [6] ReqLimitRevoke            -- 限价单撤单"<<endl;
		cerr<<" [7] ReqQryAccountInfo         -- 查询账户信息"<<endl;
		cerr<<" [8] ReqQryCommodity           -- 请求查询商品信息"<<endl;
		cerr<<" [9] ReqQryPositionOrder       -- 请求查询持仓单信息"<<endl;
		cerr<<" [10] ReqQryLimitOrder		  -- 请求查询限价单信息"<<endl;
		cerr<<" [11] ReqQryClosePosition	  -- 请求查询平仓单信息"<<endl;
		cerr<<" [12] ReqQryHoldPositionTotal  -- 请求查询持仓单总量"<<endl;
		cerr<<" [13] ReqQryMarketStatus		  -- 请求查询市场状态"<<endl;
		cerr<<" [14] 显示市场行情"<<endl;
		cerr<<" [15] 取消显示市场行情"<<endl;
		cerr<<" [0] Exit                      -- 退出"<<endl;
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
		cerr<<" 持仓ID > "; cin>>nHoldPositionID; 
		cerr<<" 商品ID > "; cin>>nCommodityID; 
		cerr<<" 平仓数量 > "; cin>>nQuantity; 
		cerr<<" 交易范围 允许的点差范围 > "; cin>>nTradeRange; 
		cerr<<" 平仓价格 > "; cin>>dbPrice; 
		CXCloseMarketOrderParam mCloseOrder;
		mCloseOrder.nHoldPositionID = nHoldPositionID;			///< 持仓ID
		mCloseOrder.nCommodityID = nCommodityID;				///< 商品ID
		mCloseOrder.nQuantity = nQuantity;						///< 平仓数量
		mCloseOrder.nTradeRange = nTradeRange;					///< 交易范围
		mCloseOrder.dbPrice = dbPrice;							///< 平仓价格
		mCloseOrder.nClosePositionType = 1;						///< 平仓类型 填1
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
		cerr<<" 商品ID > "; cin>>nCommodityID; 
		cerr<<" 平仓单价 > "; cin>>dbClosePrice; 
		cerr<<" 过期类型 > "; cin>>nExpireType;
		cerr<<" 持仓ID > "; cin>>nHoldPositionID;
		cerr<<" 下单类型 > "; cin>>nOrderType;      
		cerr<<" 平仓数量 > "; cin>>nQuantity;   
		cerr<<" 止盈价格 > "; cin>>dbSLPrice;   
		cerr<<" 止损价格 > "; cin>>dbTPPrice;   
		CXCloseLimitOrderParam lCloseOrder;
		lCloseOrder.nCommodityID = nCommodityID;			///< 商品ID
		lCloseOrder.dbClosePrice = dbClosePrice;		///< 平仓单价
		lCloseOrder.nExpireType = nExpireType;			///< 过期类型
		lCloseOrder.nHoldPositionID = nHoldPositionID;	///< 持仓ID
		lCloseOrder.nOrderType = nOrderType;				///< 下单类型
		lCloseOrder.nQuantity = nQuantity;				///< 平仓数量
		lCloseOrder.dbSLPrice = dbSLPrice;			///< 止盈价格
		lCloseOrder.dbTPPrice = dbTPPrice;			///< 止损价格
		p->ReqLimitClosePosition(&lCloseOrder); 
		break;
			}
	case 6: { 
		long long nLimitOrderID = 0;
		int nCommodityID = 0;
		int nOrderType = 0;
		int nLimitType = 0;
		cerr<<" 限价单ID > "; cin>>nLimitOrderID; 
		cerr<<" 商品ID > "; cin>>nCommodityID; 
		cerr<<" 下单类型 > "; cin>>nOrderType;
		cerr<<" 限价单类型 > "; cin>>nLimitType;
		CXLimitRevokeParam limitRevoke;
		limitRevoke.nLimitOrderID = nLimitOrderID;	///< 限价单ID
		limitRevoke.nCommodityID = nCommodityID;			///< 商品ID
		limitRevoke.nOrderType = nOrderType;				///< 下单类型
		limitRevoke.nLimitType = nLimitType;				///< 限价单类型
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

