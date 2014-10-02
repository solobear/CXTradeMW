package com.cxtrade.mw.client.reqresp;

import com.google.gson.JsonElement;

/**
 * 回传消息
 * @author Administrator
 *
 */
public class ResponseMsg {
     private String respDesc;
     private int respErr;
     private int respID;
     private  JsonElement  respJsons;
     
     
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
	public JsonElement getRespJsons() {
		return respJsons;
	}
	public void setRespJsons(JsonElement respJsons) {
		this.respJsons = respJsons;
	}
}
