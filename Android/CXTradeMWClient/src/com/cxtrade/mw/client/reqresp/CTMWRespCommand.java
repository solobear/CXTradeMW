package com.cxtrade.mw.client.reqresp;

/**
 * 回传类型表
 * @author Eric
 * 
 */
public interface CTMWRespCommand {
	// Respone Type
	int RESP_OnRtnUserLogin              = 1001;
	int RESP_OnRtnQuote                  = 1002;
	int RESP_OnRtnOpenMarketOrder        = 1003;
	int RESP_OnRtnCloseMarketOrder       = 1004;
	int RESP_OnRtnOpenLimitOrder         = 1005;
	int RESP_OnRtnLimitClosePosition     = 1006;
	int RESP_OnRtnRevokeLimitOrder       = 1007;
	int RESP_OnRtnSysBulletin            = 1008;
	int RESP_OnRspUserLogin              = 1009;
	int RESP_OnRspOpenMarketOrder        = 1010;
	int RESP_OnRspCloseMarketOrder       = 1011;
	int RESP_OnRspOpenLimitOrder         = 1012;
	int RESP_OnRspLimitClosePosition     = 1013;
	int RESP_OnRspLimitRevoke            = 1014;
	int RESP_OnRspCloseMarketOrderMany   = 1015;

	int RESP_OnRspQryAccountInfo         = 1016;
	int RESP_OnRspQryCommodity           = 1017;
	int RESP_OnRspQryPositionOrder       = 1018;
	int RESP_OnRspQryLimitOrder          = 1019;
	int RESP_OnRspQryClosePosition       = 1020;
	int RESP_OnRspQryHoldPositionTotal   = 1021;
	int RESP_OnRspQryMarketStatus        = 1022;
	int RESP_OnRspQryHoldPositionByID    = 1023;
	int RESP_OnRspQryLimitOrderByID      = 1024;
	int RESP_OnRspQryClosePositionByID   = 1025;
	int RESP_OnRspQryHoldPositionTotalByCommodityID = 1026;
	int RESP_OnRspQryCommodityQuote      = 1027;
	int RESP_OnRspQryOpenMarketOrderConf = 1028;
	int RESP_OnRspQryOpenLimitOrderConf  = 1029;
	int RESP_OnRspQryCloseMarketOrderConf   = 1030;
	int RESP_OnRspQryLimitClosePositionConf = 1031;
}
