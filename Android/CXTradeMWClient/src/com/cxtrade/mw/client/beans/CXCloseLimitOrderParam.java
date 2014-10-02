package com.cxtrade.mw.client.beans;

public class CXCloseLimitOrderParam {
	int nCommodityID;			///< 商品ID
	double dbClosePrice;		///< 平仓单价
	int nExpireType;			///< 过期类型
	long nHoldPositionID;	    ///< 持仓ID
	int nOrderType;				///< 下单类型
	int nQuantity;				///< 平仓数量
	double dbSLPrice;			///< 止盈价格
	double dbTPPrice;			///< 止损价格
	
	
	public CXCloseLimitOrderParam(int nCommodityID, double dbClosePrice, int nExpireType, long nHoldPositionID, int nOrderType, int nQuantity, double dbSLPrice, double dbTPPrice) {
		super();
		this.nCommodityID = nCommodityID;
		this.dbClosePrice = dbClosePrice;
		this.nExpireType = nExpireType;
		this.nHoldPositionID = nHoldPositionID;
		this.nOrderType = nOrderType;
		this.nQuantity = nQuantity;
		this.dbSLPrice = dbSLPrice;
		this.dbTPPrice = dbTPPrice;
	}
	
	
	public int getnCommodityID() {
		return nCommodityID;
	}
	public void setnCommodityID(int nCommodityID) {
		this.nCommodityID = nCommodityID;
	}
	public double getDbClosePrice() {
		return dbClosePrice;
	}
	public void setDbClosePrice(double dbClosePrice) {
		this.dbClosePrice = dbClosePrice;
	}
	public int getnExpireType() {
		return nExpireType;
	}
	public void setnExpireType(int nExpireType) {
		this.nExpireType = nExpireType;
	}
	public long getnHoldPositionID() {
		return nHoldPositionID;
	}
	public void setnHoldPositionID(long nHoldPositionID) {
		this.nHoldPositionID = nHoldPositionID;
	}
	public int getnOrderType() {
		return nOrderType;
	}
	public void setnOrderType(int nOrderType) {
		this.nOrderType = nOrderType;
	}
	public int getnQuantity() {
		return nQuantity;
	}
	public void setnQuantity(int nQuantity) {
		this.nQuantity = nQuantity;
	}
	public double getDbSLPrice() {
		return dbSLPrice;
	}
	public void setDbSLPrice(double dbSLPrice) {
		this.dbSLPrice = dbSLPrice;
	}
	public double getDbTPPrice() {
		return dbTPPrice;
	}
	public void setDbTPPrice(double dbTPPrice) {
		this.dbTPPrice = dbTPPrice;
	}
}
