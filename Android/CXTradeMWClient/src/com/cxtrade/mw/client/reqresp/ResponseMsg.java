package com.cxtrade.mw.client.reqresp;

import com.google.gson.JsonElement;

/**
 * 回传消息
 * @author Administrator
 *
 */
public class ResponseMsg {
	private int respID;       // 返回类型标识
    private String respDesc;  // 返回消息类型描述
    private int respErr;      // 返回错误代码
    private boolean isLast;   // 是否最后一条： 少数几个需要
	private JsonElement respJsons;  // 消息内容

	public String getRespDesc() {
		return respDesc;
	}
	public void setRespDesc(String respDesc) {
		this.respDesc = respDesc;
	}
	public int getRespErr() {
		return respErr;
	}
	public void setRespErr(int respErr) {
		this.respErr = respErr;
	}
	public int getRespID() {
		return respID;
	}
	public void setRespID(int respID) {
		this.respID = respID;
	}
    public boolean isLast() {
		return isLast;
	}
	public void setLast(boolean isLast) {
		this.isLast = isLast;
	}
	public JsonElement getRespJsons() {
		return respJsons;
	}
	public void setRespJsons(JsonElement respJsons) {
		this.respJsons = respJsons;
	}
}
