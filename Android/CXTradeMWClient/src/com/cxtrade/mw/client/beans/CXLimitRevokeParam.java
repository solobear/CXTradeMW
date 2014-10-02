package com.cxtrade.mw.client.beans;

public class CXLimitRevokeParam {
	long nLimitOrderID;	        ///< 限价单ID
	int nCommodityID;			///< 商品ID
	int nOrderType;				///< 下单类型
	int nLimitType;				///< 限价单类型
	
	public CXLimitRevokeParam(long nLimitOrderID, int nCommodityID, int nOrderType, int nLimitType) {
		super();
		this.nLimitOrderID = nLimitOrderID;
		this.nCommodityID = nCommodityID;
		this.nOrderType = nOrderType;
		this.nLimitType = nLimitType;
	}
	
	
	public long getnLimitOrderID() {
		return nLimitOrderID;
	}
	public void setnLimitOrderID(long nLimitOrderID) {
		this.nLimitOrderID = nLimitOrderID;
	}
	public int getnCommodityID() {
		return nCommodityID;
	}
	public void setnCommodityID(int nCommodityID) {
		this.nCommodityID = nCommodityID;
	}
	public int getnOrderType() {
		return nOrderType;
	}
	public void setnOrderType(int nOrderType) {
		this.nOrderType = nOrderType;
	}
	public int getnLimitType() {
		return nLimitType;
	}
	public void setnLimitType(int nLimitType) {
		this.nLimitType = nLimitType;
	}
}
