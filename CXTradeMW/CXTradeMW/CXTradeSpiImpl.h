#pragma once
#include "CXTradeMWSocket.h"
#include "api/TradeApi.h"
#include "libs/jsoncpp/json.h"

using namespace std;
using namespace Json;

class CXTradeSpiImpl : public CTradeSpi
{
private:
	CTradeApi *m_pTradeApi;
	CXMWSocket *m_mwSocket;
	bool m_bObMD;

public:

	CXTradeSpiImpl(CTradeApi* api, CXMWSocket* mwSocket){
		m_pTradeApi = api;
		m_mwSocket = mwSocket;
		m_bObMD = true;
	};

	///���ͽ�����������ݵ��ͻ���
	///@param������,json��ʽ
	virtual void CXTradeSpiImpl::SendBack(Json::Value &jsonRoot);

public:

	///��¼��Ӧ����
	///@param pLoginEvent���û���¼��Ϣ��
	virtual void OnRtnUserLogin(const CXProcessResult *ProcResult);

	///ʵʱ��������
	///@param pQuoteEvent��������Ϣ��
	virtual void OnRtnQuote(const CXRealTimeQuote *Quote);

	///�м۵����ֻر���Ϣ����
	///@param pOpenMarketOrder���м۵����ֻر���Ϣ��
	virtual void OnRtnOpenMarketOrder(long long HoldPositionID, const CXProcessResult *ProcResult);

	///�м۵�ƽ�ֻر���Ϣ����
	///@param pCloseMarketOrder���м۵�ƽ�ֻر���Ϣ��
	virtual void OnRtnCloseMarketOrder(long long HoldPositionID, const CXProcessResult *ProcResult);

	///�޼۵����ֻر���Ϣ����
	///@param pOpenLimitOrder���޼۵����ֻر���Ϣ��
	virtual void OnRtnOpenLimitOrder(long long LimitOrderID, const CXProcessResult *ProcResult);

	///�޼۵�ƽ�ֻر���Ϣ����
	///@param pOpenLimitOrder���޼۵�ƽ�ֻر���Ϣ��
	virtual void OnRtnLimitClosePosition(long long HoldPositionID, const CXProcessResult *ProcResult);

	///�޼۵������ر���Ϣ����
	///@param pRevokeLimitOrder���޼۵������ر���Ϣ��
	virtual void OnRtnRevokeLimitOrder(long long LimitOrderID, const CXProcessResult *ProcResult);

	///ϵͳ֪ͨ��Ϣ����
	///@param pSysBulletin��ϵͳ֪ͨ��Ϣ��
	virtual void OnRtnSysBulletin(const CXSysBulletinInfo *pSysBulletInfo);

	///�û���¼�ر�
	///@param pszLoginAccount���˻���
	///@param errCode��������Ϣ��
	virtual void OnRspUserLogin(const char* pszLoginAccount, int errCode, bool isLast);

	///�м۵����ֻر�
	///@param pOnRspOpenMarketOrderField���м۵����ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspOpenMarketOrder(const CXOpenMarketOrderParam *pOnRspOpenMarketOrderField, int errCode, bool isLast);

	///�м۵�ƽ�ֻر�
	///@param pOnRspCloseMarketOrderField���м۵�ƽ�ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspCloseMarketOrder(const CXCloseMarketOrderParam *pOnRspCloseMarketOrderField, int errCode, bool isLast);

	///�޼۵����ֻر�
	///@param pOnRspOpenLimitOrderField���޼۵����ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspOpenLimitOrder(const CXOpenLimitOrderParam *pOnRspOpenLimitOrderField, int errCode, bool isLast);

	///�޼۵�ƽ�ֻر�
	///@param pOnRspCloseLimitOrderField���޼۵�ƽ�ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspLimitClosePosition(const CXCloseLimitOrderParam *pOnRspCloseLimitOrderField, int errCode, bool isLast);

	///�����ر�
	///@param pOnRspLimitRevokeField�������ṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspLimitRevoke(const CXLimitRevokeParam *pOnRspLimitRevokeField, int errCode, bool isLast);

	///�м۵�����ƽ�ֻر�
	///@param pOnRspCloseMarketOrderManyField���м۵�����ƽ�ֽṹ��
	///@param errCode��������Ϣ��
	virtual void OnRspCloseMarketOrderMany(const CXCloseMarketOrderManyParam *pOnRspCloseMarketOrderManyField, int errCode, bool isLast);

	///��ѯ�˻���Ϣ�ر�
	///@param account���˻���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryAccountInfo(const CXAccountInfo *account, int errCode, bool isLast);

	///��ѯ��Ʒ��Ϣ�ر�
	///@param vCommodity����Ʒ��Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryCommodity(const CXCommodityInfo* vCommodity, int errCode, bool isLast);

	///��ѯ�ֲֵ���Ϣ�ر�
	///@param vHoldPosition���ֲֵ���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryPositionOrder(const CXHoldPositionInfo* vHoldPosition, int errCode, bool isLast);

	///��ѯ�޼۵���Ϣ�ر�
	///@param vLimitOrder���޼۵���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryLimitOrder(const CXLimitOrderInfo* vLimitOrder, int errCode, bool isLast);

	///��ѯƽ����Ϣ�ر�
	///@param vClosePosition��ƽ����Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryClosePosition(const CXClosePositionInfo* vClosePosition, int errCode, bool isLast);

	///��ѯ�ֲֵ������ر�
	///@param vTotal���ֲֵ�������
	///@param errCode��������Ϣ��
	virtual void OnRspQryHoldPositionTotal(const CXHoldPositionTotalInfo* vTotal, int errCode, bool isLast);

	///��ѯ�г�������״̬�ر�
	///@param nMarketStatus���г�������״̬�� MARKET_STATUS_OPEN��0 MARKET_STATUS_CLOSE��1
	///@param errCode��������Ϣ��
	virtual void OnRspQryMarketStatus(int nMarketStatus, int errCode, bool isLast);

	///���ݳֲֵ�ID����ȡ�ֲֵ���Ϣ�ر�
	///@param pHoldPosition���ֲֵ���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryHoldPositionByID(const CXHoldPositionInfo* pHoldPosition, int errCode, bool isLast);

	///�����޼۵�ID����ȡ�޼۵���Ϣ�ر�
	///@param pLimitOrder���޼۵���Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryLimitOrderByID(const CXLimitOrderInfo* pLimitOrder, int errCode, bool isLast);

	///����ƽ�ֵ�ID����ȡƽ����Ϣ�ر�
	///@param pClosePosition��ƽ����Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryClosePositionByID(const CXClosePositionInfo* pClosePosition, int errCode, bool isLast);

	///������ƷID����ȡ�ֲֻ�����Ϣ�ر�
	///@param pTotal���ֲֻ�����Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryHoldPositionTotalByCommodityID(const CXHoldPositionTotalInfo* pTotal, int errCode, bool isLast);

	///������ƷID����ȡʵʱ����ر�
	///@param quote��ʵʱ���顣
	///@param errCode��������Ϣ��
	virtual void OnRspQryCommodityQuote(const CXRealTimeQuote* quote, int errCode, bool isLast);

	///������ƷID����ȡ���м۽��ֵ�������Ϣ�ر�
	///@param pConf���м۽��ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryOpenMarketOrderConf(const CXOpenMarketOrderConf* pConf, int errCode, bool isLast);

	///������ƷID����ȡ���޼۽��ֵ�������Ϣ�ر�
	///@param pConf���޼۽��ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryOpenLimitOrderConf(const CXOpenLimitOrderConf* pConf, int errCode, bool isLast);

	///������ƷID����ȡ���м�ƽ�ֵ�������Ϣ�ر�
	///@param pConf���м�ƽ�ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryCloseMarketOrderConf(const CXCloseMarketOrderConf* pConf, int errCode, bool isLast);

	///������ƷID����ȡ�޼�ƽ�ֵ�������Ϣ�ر�
	///@param pConf���޼�ƽ�ֵ�������Ϣ��
	///@param errCode��������Ϣ��
	virtual void OnRspQryLimitClosePositionConf(const CXLimitClosePositionConf* pConf, int errCode, bool isLast);


};

