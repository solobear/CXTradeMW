#pragma once

#include <vector>

#define  CX_MAX_CUSTOMERNAME_LEN             128
#define  CX_MAX_COMMODITYNAME_LEN            128
#define  CX_MAX_COMMODITYCODE_LEN            16
#define  CX_MAX_COMMODITYTYPE_LEN            16
#define  CX_MAX_LOGINACCONT_LEN              32
#define  CX_MAX_MESSAGE_LEN                  512

#define  CX_MAX_BULLETIN_HEADER_LEN          128
#define  CX_MAX_BULLETIN_CONTENT_LEN         4000
#define  CX_MAX_PUBLISHERNAME_LEN            64

enum MARKET_STATUS
{
	CX_MARKET_STATUS_CLOSE = 0,
	CX_MARKET_STATUS_OPEN  = 1,
};

enum
{
	CX_MSG_STATUS_NO_UPDATE      = 1,
	CX_MSG_STATUS_UPDATED        = 2,
	CX_MSG_STATUS_NO_PERMISSION  = 3,
	CX_MSG_STATUS_NOT_EXIST      = 4,
	CX_MSG_STATUS_INIT_FAILED    = 5,
};

enum
{
	CX_LIMITTYPE_OPENLIMIT  = 1,
	CX_LIMITTYPE_SL_CLOSE   = 3,
	CX_LIMITTYPE_TP_CLOSE   = 2,
};

enum
{
	CX_OPENDIRECTOR_BUY    = 1,
	CX_OPENDIRFCTOR_SELL   = 2,
};

enum
{
	CX_INIT_MESSAGE_START  = 1,
	CX_INIT_MESSAGE_END    = 2,
};

/// �������ṹ��
struct CXProcessResult
{
	int  RetCode;				///< ������
	char Message[CX_MAX_MESSAGE_LEN];		///< ������Ϣ
};

/// ʵʱ����ṹ��
struct CXRealTimeQuote
{
	int       CommodityID;	///< ��ƷID
	double    SellPrice;	///< ������
	double    BuyPrice;		///< �����
	double    HighPrice;	///< ��߼�
	double    LowPrice;		///< ��ͼ�
	long long QuoteTime;	///< ʱ�̵�
};

/// ����ṹ��
struct CXSysBulletinInfo
{
	int       LoginID;		///< ��¼ID
	long long BulletinID;   ///< ����ID
	int       TradeMode;		///< ����ģʽ
	int       BulletinType;		///< ��������
	int       BulletinPriorty;  ///< ���ȼ�
	char      BulletinHeader[CX_MAX_BULLETIN_HEADER_LEN];		///< ������Ϣͷ
	char      BulletinContent[CX_MAX_BULLETIN_CONTENT_LEN];		///< ������Ϣ����
	char      PublisherName[CX_MAX_PUBLISHERNAME_LEN];		///< ��������
	int       BulletinMethod;		///< ���淽ʽ
};

/// �м۵�����
struct CXOpenMarketOrderParam
{
	int nCommodityID;		///< ��ƷID
	int nOpenDirector;		///< ���ַ���
	double dbPrice;			///< ���ֵ���
	int nQuantity;			///< ��������
	double dbTradeRange;	///< ���׷�Χ
	int nOrderType;			///< �µ�����
};

/// �м�ƽ�ֵ���νṹ��
struct CXCloseMarketOrderParam
{
	long long nHoldPositionID;		///< �ֲ�ID
	int nCommodityID;				///< ��ƷID
	int nQuantity;					///< ƽ������
	int nTradeRange;				///< ���׷�Χ ����ĵ�Χ
	double dbPrice;					///< ƽ�ּ۸�
	int nClosePositionType;			///< ƽ������
};

/// �޼۵�������νṹ��
struct CXOpenLimitOrderParam
{
	int nCommodityID;			///< ��ƷID
	int nExpireType;			///< ��������
	int nOpenDirector;			///< ���ַ���
	int nQuantity;				///< ��������
	int nOrderType;				///< �µ�����
	double dbOrderPrice;		///< ���ֵ���
	double dbTPPrice;			///< ֹӯ�۸�
	double dbSLPrice;			///< ֹ��۸�
};

/// �޼۵�ƽ����νṹ��
struct CXCloseLimitOrderParam
{
	int nCommodityID;			///< ��ƷID
	double dbClosePrice;		///< ƽ�ֵ���
	int nExpireType;			///< ��������
	long long nHoldPositionID;	///< �ֲ�ID
	int nOrderType;				///< �µ�����
	int nQuantity;				///< ƽ������
	double dbSLPrice;			///< ֹӯ�۸�
	double dbTPPrice;			///< ֹ��۸�
};

/// �޼۵�������νṹ��
struct CXLimitRevokeParam
{
	long long nLimitOrderID;	///< �޼۵�ID
	int nCommodityID;			///< ��ƷID
	int nOrderType;				///< �µ�����
	int nLimitType;				///< �޼۵�����
};

/// ����ƽ����νṹ��
struct CXCloseMarketOrderManyParam
{
	int nCommodityID;			///< ��ƷID
	int nQuantity;				///< ƽ������
	int nTradeRange;			///< ���׷�Χ
	double dbPrice;				///< ƽ�ּ۸�
	int nClosePositionType;		///< ƽ������
	int nCloseDirector;			///< ƽ�ַ���
};

/// �˻���Ϣ�ṹ��
struct CXAccountInfo
{
	char   Account[CX_MAX_LOGINACCONT_LEN];	///< �˻���
	char   LoginAccount[CX_MAX_LOGINACCONT_LEN];	///< ��¼��
	char   CustomerName[CX_MAX_CUSTOMERNAME_LEN];	///< �ͻ�����
	double NAVPrice;            ///< ��ֵ
	double Amount;              ///< ���
	double OpenProfit;          ///< ����ӯ��
	double ExchangeReserve;     ///< ����׼����
	double PerformanceReserve;  ///< ��Լ׼����
	double FrozenReserve;       ///< ����׼����
	double RiskRate;            ///< ������
};

/// ��Ʒ��Ϣ�ṹ��
struct CXCommodityInfo
{
	int       CommodityID;	///< ��ƷID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];		///< ��Ʒ����
	long long CommodityRight;	///< ��ƷȨ��
	long long TradeRight;	///< ����Ȩ��
	double    AgreeUnit;	///< ��Լ��λ
	int       Currency;		///< ��������
	double    MinQuoteChangeUnit;	///< ��С����䶯��λ
	double    MinPriceUnit;	///< ��С�۸�λ
	double    FixedSpread;	///< �̶����
	double    BuyPrice;		///< �����
	double    SellPrice;	///< ������
	double    HighPrice;	///< ��߼�
	double    LowPrice;		///< ��ͼ�
	long long QuoteTime;	///< ʱ�̵�
};

/// �ֲֵ���Ϣ�ṹ��
struct CXHoldPositionInfo
{
	long long HoldPositionID;	///< �ֲֵ�ID
	int       CommodityID;		///< ��ƷID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];	///< ��Ʒ����
	int       OpenType;			///< ��������
	int       OpenDirector;		///< ���ַ���
	int       Quantity;			///< �ֲ�����
	double    OpenPrice;		///< ���ּ۸�
	double    HoldPositionPrice;	///< �ֲּ�
	double    ClosePrice;		///< ƽ�ּ�
	long long SLLimitOrderID;	///< ֹ��ID
	double    SLPrice;			///< ֹ���
	long long TPLimitOrderID;	///< ֹӯ��ID
	double    TPPrice;			///< ֹӯ��
	double    OpenProfit;		///< ����ӯ��
	double    CommissionAmount;	///< Ӷ��
	long long OpenDate;			///< ����ʱ��
	double    AgreeMargin;		///< ��Լ��֤��
	double    Freezemargin;		///< ���ᱣ֤��
	double    OverdueFindFund;	///< ���ɽ�
};

/// �޼۵���Ϣ�ṹ��
struct CXLimitOrderInfo
{
	long long LimitOrderID;		///< �޼۵�ID
	int       CommodityID;		///< ��ƷID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];		///< ��Ʒ����
	int       LimitType;		///< �޼۵�����
	int       OrderType;		///< ��������
	int       OpenDirector;		///< ���ַ���
	double    OrderPrice;		///< ���ּ�
	double    SLPrice;			///< ֹ���
	double    TPPrice;			///< ֹӯ��
	int       OpenQuantity;		///< �ֲ�����
	long long CreateDate;		///< ����ʱ��
	long long ExpireType;		///< ʧЧ����
	long long UpdateDate;		///< ����ʱ��
	double    FreeszMargin;		///< ���ᱣ֤��
};

/// ƽ�ֵ���Ϣ�ṹ��
struct CXClosePositionInfo
{
	long long ClosePositionID;	///< ƽ�ֵ�ID
	int       CommodityID;		///< ��ƷID
	char      CommodityName[CX_MAX_COMMODITYNAME_LEN];	///< ��Ʒ����
	int       CloseDirector;	///< ƽ�ַ���
	double    OpenPrice;		///< ���ּ�
	double    HoldPrice;		///< �ֲּ�
	double    ClosePrice;		///< ƽ�ּ�
	int       Quantity;			///< �ֲ�����
	long long OpenPositionID;	///< ���ֵ�ID
	double    CommissionAmount;	///< Ӷ��
	long long OpenDate;			///< ����ʱ��
	long long CloseDate;		///< ƽ��ʱ��
	int       MemberID;			///< ��ԱID
	int       OpenType;			///< ��������
	int       CloseType;		///< ƽ������
};

/// �ֲֻ��ܵ���Ϣ�ṹ��
struct CXHoldPositionTotalInfo
{
	int    CommodityID;			///< ��ƷID
	char   CommodityName[CX_MAX_COMMODITYNAME_LEN];	///<  ��Ʒ����
	int    OpenDirector;		///< ���ַ���
	int    Quantity;			///< �ֲ�����
	double OpenPriceTotal;		///< ������ֵ
	double AvgOpenPrice;		///< ���־���
	double HoldPriceTotal;		///< �ֲ���ֵ
	double AvgHoldPrice;		///< �ֲ־���
	double ClosePrice;			///< ƽ�ּ�
	double OpenProfit;			///< ����ӯ��
};

///  �м۵�����������Ϣ�ṹ��
struct CXOpenMarketOrderConf
{
	int       CommodityID;		///< ��ƷID
	double    MinQuantity;		///< �������
	double    MaxQuantity;		///< ��С������
};

/// �޼۵�����������Ϣ�ṹ��
struct CXOpenLimitOrderConf
{
	int    CommodityID;			///< ��ƷID
	double MinQuantity;			///< ��С������
	double MaxQuantity;			///< �������
	double LimitSpread;			///< �޼۵��
	double FixSpread;			///< �̶����
	double TPSpread;			///< ֹӯ���
	double SLSpread;			///< ֹ����
	double MinPriceUnit;		///< ��С�۸�λ
	double AgreeUnit;			///< ��Լ��λ
};

/// �м۵�ƽ��������Ϣ�ṹ��
struct CXCloseMarketOrderConf
{
	int       CommodityID;		///< ��ƷID
	double    MinQuantity;		///< ��С������
	double    MaxQuantity;		///< �������
};

/// �޼۵�ƽ��������Ϣ�ṹ��
struct CXLimitClosePositionConf
{
	int    CommodityID;			///< ��ƷID
	double FixedSpread;			///< �̶����
	double TPSpread;			///< ֹӯ���
	double SLSpread;			///< ֹ����
	double MinPriceUnit;		///< ��С�۸�λ
	double AgreeUnit;			///< ��Լ��λ
};
