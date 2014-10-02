package com.cxtrade.mw.client.reqresp;

/**
 * 请求类型表
 * @author Eric
 * 
 */
public interface CTMWReqCommand {

	int Req_UserLogin             = 100;

	int Req_OpenMarketOrder       = 101;
	int Req_CloseMarketOrder      = 102;
	int Req_OpenLimitOrder        = 103;
	int Req_LimitClosePosition    = 104;
	int Req_LimitRevoke           = 105;
	int Req_CloseMarketOrderMany  = 106;

	int ReqQry_AccountInfo        = 107;
	int ReqQry_Commodity          = 108;
	int ReqQry_MarketStatus       = 109;
	int ReqQry_PositionOrder      = 110;
	int ReqQry_LimitOrder         = 111;
	int ReqQry_ClosePosition      = 112;
	int ReqQry_HoldPositionTotal  = 113;
	int ReqQry_HoldPositionByID   = 114;
	int ReqQry_LimitOrderByID     = 115;
	int ReqQry_ClosePositionByID  = 116;
	int ReqQry_HoldPositionTotalByCommodityID = 117;
	int ReqQry_CommodityQuote         = 118;
	int ReqQry_OpenMarketOrderConf    = 119;
	int ReqQry_OpenLimitOrderConf     = 120;
	int ReqQry_CloseMarketOrderConf   = 121;
	int ReqQry_LimitClosePositionConf = 122;

	int Req_Close                = 200;

}
