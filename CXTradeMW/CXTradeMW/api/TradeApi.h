#pragma once

#include "TradeApiStruct.h"

#ifdef LIB_USER_API_EXPORT
#define USER_API_EXPORT __declspec(dllexport)
#else
#define USER_API_EXPORT __declspec(dllimport)
#endif

class CTradeSpi
{
public:
	///��¼��Ӧ����
	///@param pLoginEvent���û���¼��Ϣ��
	//virtual void OnRtnUserLogin(const TLoginEvent* pLoginEvent) {};
	virtual void OnRtnUserLogin(const CXProcessResult *ProcResult) {};

	///ʵʱ��������
	///@param pQuoteEvent��������Ϣ��
	//virtual void OnRtnQuote(const TQuoteEvent *pQuoteEvent) {};
	virtual void OnRtnQuote(const CXRealTimeQuote *Quote) {};

	///�м۵����ֻر���Ϣ����
	///@param pOpenMarketOrder���м۵����ֻر���Ϣ��
	//virtual void OnRtnOpenMarketOrder(const TOpenMarketOrderEvent *pOpenMarketOrder) {};
	virtual void OnRtnOpenMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult) {};

	///�м۵�ƽ�ֻر���Ϣ����
	///@param pCloseMarketOrder���м۵�ƽ�ֻر���Ϣ��
	//virtual void OnRtnCloseMarketOrder(const TCloseMarketOrderEvent *pCloseMarketOrder) {};
	virtual void OnRtnCloseMarketOrder(long long HoldPositionID,const CXProcessResult *ProcResult) {};

	///�޼۵����ֻر���Ϣ����
	///@param pOpenLimitOrder���޼۵����ֻر���Ϣ��
	//virtual void OnRtnOpenLimitOrder(const TOpenLimitOrderEvent *pOpenLimitOrder) {};
	virtual void OnRtnOpenLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult) {};

	///�޼۵�ƽ�ֻر���Ϣ����
	///@param pOpenLimitOrder���޼۵�ƽ�ֻر���Ϣ��
	//virtual void OnRtnLimitClosePosition(const TLimitClosePositionEvent *pLimitClosePosition) {};
	virtual void OnRtnLimitClosePosition(long long HoldPositionID,const CXProcessResult *ProcResult) {};

	///�޼۵������ر���Ϣ����
	///@param pRevokeLimitOrder���޼۵������ر���Ϣ��
	//virtual void OnRtnRevokeLimitOrder(const TRevokeLimitOrderEvent *pRevokeLimitOrder) {};
	virtual void OnRtnRevokeLimitOrder(long long LimitOrderID,const CXProcessResult *ProcResult) {};

	///ϵͳ֪ͨ��Ϣ����
	///@param pSysBulletin��ϵͳ֪ͨ��Ϣ��
	//virtual void OnRtnSysBulletin(const TSysBulletinEvent *pSysBulletin) {};
	virtual void OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletInfo) {};

	///�û���¼�ر�
	///@param pszLoginAccount���˻���
	///@param errCode��������Ϣ��
	virtual void OnRspUserLogin(const char* pszLoginAccount, int errCode) {};

	///�м۵����ֻر�
	///@param pOnRspOpenMarketOrderField���м۵����ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pOnRspOpenMarketOrderField, int errCode) {};

	///�м۵�ƽ�ֻر�
	///@param pOnRspCloseMarketOrderField���м۵�ƽ�ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode) {};

	///�޼۵����ֻر�
	///@param pOnRspOpenLimitOrderField���޼۵����ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode) {};

	///�޼۵�ƽ�ֻر�
	///@param pOnRspCloseLimitOrderField���޼۵�ƽ�ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode) {};

	///�����ر�
	///@param pOnRspLimitRevokeField�������ṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode) {};

	///�м۵�����ƽ�ֻر�
	///@param pOnRspCloseMarketOrderManyField���м۵�����ƽ�ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode) {};

	///��ѯ�˻���Ϣ�ر�
	///@param account���˻���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryAccountInfo(const CXAccountInfo *account, int errCode) {};

	///��ѯ��Ʒ��Ϣ�ر�
	///@param vCommodity����Ʒ��Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryCommodity(std::vector<CXCommodityInfo> &vCommodity, int errCode) {};

	///��ѯ�ֲֵ���Ϣ�ر�
	///@param vHoldPosition���ֲֵ���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryPositionOrder(std::vector<CXHoldPositionInfo>& vHoldPosition, int errCode) {};

	///��ѯ�޼۵���Ϣ�ر�
	///@param vLimitOrder���޼۵���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryLimitOrder(std::vector<CXLimitOrderInfo>& vLimitOrder, int errCode) {};

	///��ѯƽ����Ϣ�ر�
	///@param vClosePosition��ƽ����Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryClosePosition(std::vector<CXClosePositionInfo>& vClosePosition, int errCode) {};

	///��ѯ�ֲֵ������ر�
	///@param vTotal���ֲֵ�������
	///@param errCode��������Ϣ��
	virtual void OnRspQryHoldPositionTotal(std::vector<CXHoldPositionTotalInfo>& vTotal, int errCode) {};

	///��ѯ�г�������״̬�ر�
	///@param nMarketStatus���г�������״̬�� MARKET_STATUS_OPEN��0 MARKET_STATUS_CLOSE��1
	///@param errCode��������Ϣ��
	virtual void OnRspQryMarketStatus(int nMarketStatus, int errCode) {};

	///���ݳֲֵ�ID����ȡ�ֲֵ���Ϣ�ر�
	///@param pHoldPosition���ֲֵ���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode) {};

	///�����޼۵�ID����ȡ�޼۵���Ϣ�ر�
	///@param pLimitOrder���޼۵���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode) {};

	///����ƽ�ֵ�ID����ȡƽ����Ϣ�ر�
	///@param pClosePosition��ƽ����Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode) {};

	///������ƷID����ȡ�ֲֻ�����Ϣ�ر�
	///@param pTotal���ֲֻ�����Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode) {};

	///������ƷID����ȡʵʱ����ر�
	///@param quote��ʵʱ���顣
	///@param errCode��������Ϣ��
	virtual void OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode) {};

	///������ƷID����ȡ���м۽��ֵ�������Ϣ�ر�
	///@param pConf���м۽��ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode) {};

	///������ƷID����ȡ���޼۽��ֵ�������Ϣ�ر�
	///@param pConf���޼۽��ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode) {};

	///������ƷID����ȡ���м�ƽ�ֵ�������Ϣ�ر�
	///@param pConf���м�ƽ�ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode) {};

	///������ƷID����ȡ�޼�ƽ�ֵ�������Ϣ�ر�
	///@param pConf���޼�ƽ�ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode) {};
};

class USER_API_EXPORT CTradeApi
{
public:
	///����UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@param pszUserApiType TradeApi����
	///@return ��������TradeApi
	static CTradeApi *CreateTradeApi(const char *pszLogPath = "");

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;

	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual int Init() = 0;

	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001����
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(const char *pszFrontAddress,int port) = 0;

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CTradeSpi *pSpi) = 0;

	///���ó������
	///@param pszAppCode��Ӧ�ý����롣
	///@param pszPassword��У�����롣
	///@param pszVendorID����ԱID��
	virtual void SetAppMessage( const char *pszAppCode,const char *pszPassword,const char *pszVendorID ) = 0;

	///�û���¼����
	///@param pszLoginAccount����¼�˻���
	///@param pszPwd����¼���롣
	virtual int ReqUserLogin(char* pszLoginAccount, char* pszPwd) = 0;

	///�м۵���������
	///@param pReqOpenMarketOrderField���м۵����ֽṹ�� �μ�TradeStruct.h
	virtual int ReqOpenMarketOrder(CXOpenMarketOrderParam *pReqOpenMarketOrderField) = 0;

	///�м۵�ƽ������
	///@param pReqCloseMarketOrderField���м۵�ƽ�ֽṹ�� �μ�TradeStruct.h
	virtual int ReqCloseMarketOrder(CXCloseMarketOrderParam *pReqCloseMarketOrderField) = 0;

	///�޼۵���������
	///@param pReqOpenLimitOrderField���޼۵����ֽṹ�� �μ�TradeStruct.h
	virtual int ReqOpenLimitOrder(CXOpenLimitOrderParam *pReqOpenLimitOrderField) = 0;

	///�޼۵�ƽ������
	///@param pReqCloseLimitOrderField���޼۵�ƽ�ֽṹ�� �μ�TradeStruct.h
	virtual int ReqLimitClosePosition(CXCloseLimitOrderParam *pReqCloseLimitOrderField) = 0;

	///�޼۵���������
	///@param pReqLimitRevokeField���޼۵������ṹ�� �μ�TradeStruct.h
	virtual int ReqLimitRevoke(CXLimitRevokeParam *pReqLimitRevokeField) = 0;

	///����ƽ�м۵�����
	///@param pReqCloseMarketOrderManyField������ƽ�м۵��ṹ�� �μ�TradeStruct.h
	virtual int ReqCloseMarketOrderMany(CXCloseMarketOrderManyParam *pReqCloseMarketOrderManyField) = 0;

	///�����ѯ�˻���Ϣ
	virtual int ReqQryAccountInfo() = 0;

	///�����ѯ��Ʒ��Ϣ
	virtual int ReqQryCommodity() = 0;

	///�����ѯ�ֲֵ���Ϣ
	virtual int ReqQryPositionOrder() = 0;

	///�����ѯ�޼۵���Ϣ
	virtual int ReqQryLimitOrder() = 0;

	///�����ѯƽ�ֵ���Ϣ
	virtual int ReqQryClosePosition() = 0;

	///�����ѯ�ֲֵ�����
	virtual int ReqQryHoldPositionTotal() = 0;

	///�����ѯ�г�״̬
	virtual int ReqQryMarketStatus() = 0;

	///���ݳֲֵ�ID����ȡ�ֲֵ���Ϣ
	///@param nHoldPositionID���ֲֵ�ID��
	virtual int ReqQryHoldPositionByID(long long nHoldPositionID) = 0;

	///�����޼۵�ID����ȡ�޼۵���Ϣ
	///@param nLimitOrderID���޼۵�ID��
	virtual int ReqQryLimitOrderByID(long long nLimitOrderID) = 0;

	///����ƽ�ֵ�ID����ȡƽ����Ϣ
	///@param nClosePositionID��ƽ�ֵ�ID��
	virtual int ReqQryClosePositionByID(long long nClosePositionID) = 0;

	///������ƷID����ȡ�ֲֻ�����Ϣ
	///@param nCommodityID����ƷID��
	///@param nOpenDirector�����ַ���ID��
	virtual int ReqQryHoldPositionTotalByCommodityID(int nCommodityID, int nOpenDirector) = 0;

	///������ƷID����ȡʵʱ����
	///@param nCommodityID����ƷID��
	virtual int ReqQryCommodityQuote(int CommoditID) = 0;

	///������ƷID����ȡ���м۽��ֵ�������Ϣ
	///@param nCommodityID����ƷID��
	virtual int ReqQryOpenMarketOrderConf(int CommodityID) = 0;

	///������ƷID����ȡ���޼۽��ֵ�������Ϣ
	///@param nCommodityID����ƷID��
	virtual int ReqQryOpenLimitOrderConf(int CommodityID) = 0;

	///������ƷID����ȡ���м�ƽ�ֵ�������Ϣ
	///@param nCommodityID����ƷID��
	virtual int ReqQryCloseMarketOrderConf(int CommodityID) = 0;

	///������ƷID����ȡ�޼�ƽ�ֵ�������Ϣ
	///@param nCommodityID����ƷID��
	virtual int ReqQryLimitClosePositionConf(int CommodityID) = 0;

protected:
	virtual ~CTradeApi(){};
};
