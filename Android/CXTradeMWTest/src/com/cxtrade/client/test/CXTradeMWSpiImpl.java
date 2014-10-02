package com.cxtrade.client.test;

import com.cxtrade.mw.client.CXTradeMWSpi;
import com.cxtrade.mw.client.reqresp.CTMWRespCommand;
import com.cxtrade.mw.client.reqresp.ResponseMsg;
import com.cxtrade.mw.client.utils.LogUtils;
import com.google.gson.Gson;
import com.google.gson.JsonObject;

/**
 * @author Eric
 * 
 */
public class CXTradeMWSpiImpl implements CXTradeMWSpi {
	private static LogUtils logger = LogUtils.getLog(CXTradeMWSpiImpl.class);

	/**
	 * @param responseJsonMsg
	 */
	public void receiveJsonMsg(String responseJsonMsg) {
		logger.info("收到消息:" + responseJsonMsg);

		// 处理第一层消息结构
		Gson gson = new Gson();
		ResponseMsg responseMsg = gson.fromJson(responseJsonMsg, ResponseMsg.class);
		switch (responseMsg.getRespID()) {
		case CTMWRespCommand.RESP_OnRtnUserLogin:
			logger.info("" + responseMsg.getRespDesc());
			JsonObject jsonObject = gson.fromJson(responseMsg.getRespJsons(), JsonObject.class);
			logger.info("RetCode:" + jsonObject.get("RetCode").getAsInt());
			break;
		case CTMWRespCommand.RESP_OnRspQryAccountInfo:
			logger.info("" + responseMsg.getRespDesc());
			break;
		default:
			logger.info("" + responseMsg.getRespDesc());
			break;
		}
	}
}
