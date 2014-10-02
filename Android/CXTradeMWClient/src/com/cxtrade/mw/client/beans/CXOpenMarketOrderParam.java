package com.cxtrade.mw.client.beans;

public class CXOpenMarketOrderParam {
	
	int nCommodityID;		///< 商品ID
	int nOpenDirector;		///< 建仓方向
	double dbPrice;			///< 建仓单价
	int nQuantity;			///< 建仓数量
	double dbTradeRange;	///< 交易范围
	int nOrderType;			///< 下单类型
	
	public CXOpenMarketOrderParam(int nCommodityID, int nOpenDirector, double dbPrice, int nQuantity, double dbTradeRange, int nOrderType) {
		super();
		this.nCommodityID = nCommodityID;
		this.nOpenDirector = nOpenDirector;
		this.dbPrice = dbPrice;
		this.nQuantity = nQuantity;
		this.dbTradeRange = dbTradeRange;
		this.nOrderType = nOrderType;
	}
	
	public int getnCommodityID() {
		return nCommodityID;
	}
	public void setnCommodityID(int nCommodityID) {
		this.nCommodityID = nCommodityID;
	}
	public int getnOpenDirector() {
		return nOpenDirector;
	}
	public void setnOpenDirector(int nOpenDirector) {
		this.nOpenDirector = nOpenDirector;
	}
	public double getDbPrice() {
		return dbPrice;
	}
	public void setDbPrice(double dbPrice) {
		this.dbPrice = dbPrice;
	}
	public int getnQuantity() {
		return nQuantity;
	}
	public void setnQuantity(int nQuantity) {
		this.nQuantity = nQuantity;
	}
	public double getDbTradeRange() {
		return dbTradeRange;
	}
	public void setDbTradeRange(double dbTradeRange) {
		this.dbTradeRange = dbTradeRange;
	}
	public int getnOrderType() {
		return nOrderType;
	}
	public void setnOrderType(int nOrderType) {
		this.nOrderType = nOrderType;
	}
}
