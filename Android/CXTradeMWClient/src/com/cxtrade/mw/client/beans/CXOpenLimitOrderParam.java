package com.cxtrade.mw.client.beans;

public class CXOpenLimitOrderParam {
	int nCommodityID;			///< 商品ID
	int nExpireType;			///< 过期类型
	int nOpenDirector;			///< 建仓方向
	int nQuantity;				///< 建仓数量
	int nOrderType;				///< 下单类型
	double dbOrderPrice;		///< 建仓单价
	double dbTPPrice;			///< 止盈价格
	double dbSLPrice;			///< 止损价格
	
	
	public CXOpenLimitOrderParam(int nCommodityID, int nExpireType, int nOpenDirector, int nQuantity, int nOrderType, double dbOrderPrice, double dbTPPrice, double dbSLPrice) {
		super();
		this.nCommodityID = nCommodityID;
		this.nExpireType = nExpireType;
		this.nOpenDirector = nOpenDirector;
		this.nQuantity = nQuantity;
		this.nOrderType = nOrderType;
		this.dbOrderPrice = dbOrderPrice;
		this.dbTPPrice = dbTPPrice;
		this.dbSLPrice = dbSLPrice;
	}
	
	
	public int getnCommodityID() {
		return nCommodityID;
	}
	public void setnCommodityID(int nCommodityID) {
		this.nCommodityID = nCommodityID;
	}
	public int getnExpireType() {
		return nExpireType;
	}
	public void setnExpireType(int nExpireType) {
		this.nExpireType = nExpireType;
	}
	public int getnOpenDirector() {
		return nOpenDirector;
	}
	public void setnOpenDirector(int nOpenDirector) {
		this.nOpenDirector = nOpenDirector;
	}
	public int getnQuantity() {
		return nQuantity;
	}
	public void setnQuantity(int nQuantity) {
		this.nQuantity = nQuantity;
	}
	public int getnOrderType() {
		return nOrderType;
	}
	public void setnOrderType(int nOrderType) {
		this.nOrderType = nOrderType;
	}
	public double getDbOrderPrice() {
		return dbOrderPrice;
	}
	public void setDbOrderPrice(double dbOrderPrice) {
		this.dbOrderPrice = dbOrderPrice;
	}
	public double getDbTPPrice() {
		return dbTPPrice;
	}
	public void setDbTPPrice(double dbTPPrice) {
		this.dbTPPrice = dbTPPrice;
	}
	public double getDbSLPrice() {
		return dbSLPrice;
	}
	public void setDbSLPrice(double dbSLPrice) {
		this.dbSLPrice = dbSLPrice;
	}
}
