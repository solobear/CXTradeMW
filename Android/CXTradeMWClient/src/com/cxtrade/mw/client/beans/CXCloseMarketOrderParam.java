package com.cxtrade.mw.client.beans;

public class CXCloseMarketOrderParam {
	long nHoldPositionID;		    ///< 持仓ID
	int nCommodityID;				///< 商品ID
	int nQuantity;					///< 平仓数量
	int nTradeRange;				///< 交易范围
	double dbPrice;					///< 持仓单价
	int nClosePositionType;			///< 平仓类型
	
	
	public CXCloseMarketOrderParam(long nHoldPositionID, int nCommodityID, int nQuantity, int nTradeRange, double dbPrice, int nClosePositionType) {
		super();
		this.nHoldPositionID = nHoldPositionID;
		this.nCommodityID = nCommodityID;
		this.nQuantity = nQuantity;
		this.nTradeRange = nTradeRange;
		this.dbPrice = dbPrice;
		this.nClosePositionType = nClosePositionType;
	}
	
	
	public long getnHoldPositionID() {
		return nHoldPositionID;
	}
	public void setnHoldPositionID(long nHoldPositionID) {
		this.nHoldPositionID = nHoldPositionID;
	}
	public int getnCommodityID() {
		return nCommodityID;
	}
	public void setnCommodityID(int nCommodityID) {
		this.nCommodityID = nCommodityID;
	}
	public int getnQuantity() {
		return nQuantity;
	}
	public void setnQuantity(int nQuantity) {
		this.nQuantity = nQuantity;
	}
	public int getnTradeRange() {
		return nTradeRange;
	}
	public void setnTradeRange(int nTradeRange) {
		this.nTradeRange = nTradeRange;
	}
	public double getDbPrice() {
		return dbPrice;
	}
	public void setDbPrice(double dbPrice) {
		this.dbPrice = dbPrice;
	}
	public int getnClosePositionType() {
		return nClosePositionType;
	}
	public void setnClosePositionType(int nClosePositionType) {
		this.nClosePositionType = nClosePositionType;
	}
	
	
}
