package com.cxtrade.mw.client;


/**
 * 交易回传信息接口
 * 
 * @author Eric
 *
 */
public interface CXTradeMWSpi {

	/**
	 * @param responseJsonMsg
	 */
	public void receiveJsonMsg(String responseJsonMsg);
}
