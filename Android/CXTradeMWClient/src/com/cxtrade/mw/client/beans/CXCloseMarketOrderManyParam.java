package com.cxtrade.mw.client.beans;

public class CXCloseMarketOrderManyParam {
	int nCommodityID;			///< 商品ID
	int nQuantity;				///< 平仓数量
	int nTradeRange;			///< 交易范围
	double dbPrice;				///< 平仓价格
	int nClosePositionType;		///< 平仓类型
	int nCloseDirector;			///< 平仓方向
	
	public CXCloseMarketOrderManyParam(int nCommodityID, int nQuantity, int nTradeRange, double dbPrice, int nClosePositionType, int nCloseDirector) {
		super();
		this.nCommodityID = nCommodityID;
		this.nQuantity = nQuantity;
		this.nTradeRange = nTradeRange;
		this.dbPrice = dbPrice;
		this.nClosePositionType = nClosePositionType;
		this.nCloseDirector = nCloseDirector;
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
	public int getnCloseDirector() {
		return nCloseDirector;
	}
	public void setnCloseDirector(int nCloseDirector) {
		this.nCloseDirector = nCloseDirector;
	}
}
