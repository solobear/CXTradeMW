///
#define Event_Ret_Success 99999
#define Order_Ret_Success 0
#define TS_1970_TO_1900  2208988800

/////////////////////////////////////////////////////////////
/// Request Type
#define REQ_CONNECT                        100

#define Req_OpenMarketOrder                101
#define Req_CloseMarketOrder               102
#define Req_OpenLimitOrder                 103
#define Req_LimitClosePosition             104
#define Req_LimitRevoke                    105
#define Req_CloseMarketOrderMany           106

#define ReqQry_AccountInfo                 107
#define ReqQry_Commodity                   108
#define ReqQry_MarketStatus                109
#define ReqQry_PositionOrder               110
#define ReqQry_LimitOrder                  111
#define ReqQry_ClosePosition               112
#define ReqQry_HoldPositionTotal           113
#define ReqQry_HoldPositionByID            114
#define ReqQry_LimitOrderByID              115
#define ReqQry_ClosePositionByID           116
#define ReqQry_HoldPositionTotalByCommodityID     117
#define ReqQry_CommodityQuote              118
#define ReqQry_OpenMarketOrderConf         119
#define ReqQry_OpenLimitOrderConf          120
#define ReqQry_CloseMarketOrderConf        121
#define ReqQry_LimitClosePositionConf      122

#define REQ_RELEASE                        200



/////////////////////////////////////////////////////////////
/// Response ID
#define RESPDESC                          "respDesc"
#define RESPID                            "respID"
#define RESPJSONS                         "respJsons"
#define RESPERRCODE                       "respErr"
#define RESPISLAST                        "isLast"

// Respone Type
#define RESP_OnRtnUserLogin                    1001
#define RESP_OnRtnQuote                        1002
#define RESP_OnRtnOpenMarketOrder              1003
#define RESP_OnRtnCloseMarketOrder             1004
#define RESP_OnRtnOpenLimitOrder               1005
#define RESP_OnRtnLimitClosePosition           1006
#define RESP_OnRtnRevokeLimitOrder             1007
#define RESP_OnRtnSysBulletin                  1008
#define RESP_OnRspUserLogin                    1009
#define RESP_OnRspOpenMarketOrder              1010
#define RESP_OnRspCloseMarketOrder             1011
#define RESP_OnRspOpenLimitOrder               1012
#define RESP_OnRspLimitClosePosition           1013
#define RESP_OnRspLimitRevoke                  1014
#define RESP_OnRspCloseMarketOrderMany         1015

#define RESP_OnRspQryAccountInfo               1016
#define RESP_OnRspQryCommodity                 1017
#define RESP_OnRspQryPositionOrder             1018
#define RESP_OnRspQryLimitOrder                1019
#define RESP_OnRspQryClosePosition             1020
#define RESP_OnRspQryHoldPositionTotal         1021
#define RESP_OnRspQryMarketStatus              1022
#define RESP_OnRspQryHoldPositionByID          1023
#define RESP_OnRspQryLimitOrderByID            1024
#define RESP_OnRspQryClosePositionByID         1025
#define RESP_OnRspQryHoldPositionTotalByCommodityID  1026
#define RESP_OnRspQryCommodityQuote            1027
#define RESP_OnRspQryOpenMarketOrderConf       1028
#define RESP_OnRspQryOpenLimitOrderConf        1029
#define RESP_OnRspQryCloseMarketOrderConf      1030
#define RESP_OnRspQryLimitClosePositionConf    1031

