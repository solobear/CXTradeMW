package com.cxtrade.client.test;

import com.cxtrade.mw.client.CXTradeMWClient;
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
	private LogUtils logger = LogUtils.getLog(CXTradeMWSpiImpl.class);

	private CXTradeMWClient client = null;
	
	/**
	 * @param responseJsonMsg
	 * 
	 * 	返回错误代码的问题，原生接口这个问题上有点乱，不过一般来说:
	 *	   返回0就是 Success
	 *	   另外：
	 *	       RetCode:
	 *	          99999 = Succss
	 *	       respErr:
	 *	            CX_MSG_STATUS_NO_UPDATE      = 1,
	 *			    CX_MSG_STATUS_UPDATED        = 2,   （SUCCESS）
	 *			    CX_MSG_STATUS_NO_PERMISSION  = 3,
	 *			    CX_MSG_STATUS_NOT_EXIST      = 4,
	 *			    CX_MSG_STATUS_INIT_FAILED    = 5,
	 */
	public void receiveJsonMsg(String responseJsonMsg) {
		//logger.info(Thread.currentThread().getName() + " 收到消息:" + responseJsonMsg);

		// 处理第一层消息结构
		Gson gson = new Gson();
		ResponseMsg responseMsg = gson.fromJson(responseJsonMsg, ResponseMsg.class);
		switch (responseMsg.getRespID()) {
		case CTMWRespCommand.RESP_OnRtnUserLogin:
			logger.info("" + responseMsg.getRespDesc());
			JsonObject jsonObject = gson.fromJson(responseMsg.getRespJsons(), JsonObject.class);
			logger.info("RetCode:" + jsonObject.get("RetCode").getAsInt());
			if(jsonObject.get("RetCode").getAsInt()!=99999){
				// 登陆失败
				if(client!=null){
					client.close();
				}
			}else{
				// 登陆成功
			}
			break;
		case CTMWRespCommand.RESP_OnRtnQuote:
			//logger.info("" + responseMsg.getRespDesc());
			break;
		default:
			logger.info(Thread.currentThread().getName() + " 收到消息:" + responseJsonMsg);
			break;
		}
	}

	@Override
	public void setClient(CXTradeMWClient cxTradeMWClient) {
		client = cxTradeMWClient;		
	}
}
