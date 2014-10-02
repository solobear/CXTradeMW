package com.cxtrade.mw.client;

import java.util.HashMap;
import java.util.Map;

import com.cxtrade.mw.client.beans.CXCloseLimitOrderParam;
import com.cxtrade.mw.client.beans.CXCloseMarketOrderManyParam;
import com.cxtrade.mw.client.beans.CXCloseMarketOrderParam;
import com.cxtrade.mw.client.beans.CXLimitRevokeParam;
import com.cxtrade.mw.client.beans.CXOpenLimitOrderParam;
import com.cxtrade.mw.client.beans.CXOpenMarketOrderParam;
import com.cxtrade.mw.client.beans.CXLoginAccount;
import com.cxtrade.mw.client.reqresp.CTMWReqCommand;
import com.cxtrade.mw.client.utils.LogUtils;
import com.google.gson.Gson;

/**
 * Java客户端
 * 
 * @author Eric
 * 
 */
public class CXTradeMWClient {
	private static LogUtils logger = LogUtils.getLog(CXTradeMWClient.class);

	// Socket
	private CXTradeMWSocket socket;

	// 消息接收
	private CXTradeMWSpi tradeMWSpi;

	
	/**
	 * @param tradeMWSpi
	 */
	public CXTradeMWClient(CXTradeMWSpi tradeMWSpi) {
		// 注册消息接收
		this.tradeMWSpi = tradeMWSpi;
	}
	
	/**
	 * 回传消息
	 * @param responseJsonMsg
	 */
	protected void dispatchResponseJsonMsg(String responseJsonMsg) {
		if(tradeMWSpi!=null){
			tradeMWSpi.receiveJsonMsg(responseJsonMsg);
		}
	}
	
	/**
	 * 连接中间件
	 * 
	 * @param address
	 * @param port
	 * @throws Exception
	 */
	public void connect(String address, int port) throws Exception {
		socket = new CXTradeMWSocket(this, address, port);
	}

	/**
	 * 关闭客户端
	 */
	public void close() {
		try {
			// 发送消息
			socket.sendReqMsg(CTMWReqCommand.Req_Close);
			
			// 关闭Socket
			if (null != socket) {
				socket.close();
			}
		} catch (Exception e) {
			logger.error(e.getMessage());
		}
	}

	/**
	 * 用户登陆
	 * 
	 * @param userName
	 * @param password
	 */
	public void login(String username, String password) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(new CXLoginAccount(username,password));

		// 发送消息
		socket.sendReqMsg(CTMWReqCommand.Req_UserLogin, jsonReq);
	}

	/**
	 * 市价单开仓请求
	 */
	public void reqOpenMarketOrder(CXOpenMarketOrderParam cxOpenMarketOrderParam) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(cxOpenMarketOrderParam);
		
		// Req_OpenMarketOrder
		socket.sendReqMsg(CTMWReqCommand.Req_OpenMarketOrder, jsonReq);
	}
	
	/**
	 * 市价单平仓请求
	 */
	public void reqCloseMarketOrder(CXCloseMarketOrderParam cxCloseMarketOrderParam) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(cxCloseMarketOrderParam);
		
		// Req_CloseMarketOrder
		socket.sendReqMsg(CTMWReqCommand.Req_CloseMarketOrder, jsonReq);
	}
	
	/**
	 * 限价单开仓请求
	 */
	public void reqOpenLimitOrder(CXOpenLimitOrderParam cxOpenLimitOrderParam) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(cxOpenLimitOrderParam);
		
		// Req_OpenLimitOrder
		socket.sendReqMsg(CTMWReqCommand.Req_OpenLimitOrder, jsonReq);
	}
	
	/**
	 * 限价单平仓请求
	 */
	public void reqLimitClosePosition(CXCloseLimitOrderParam cxCloseLimitOrderParam) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(cxCloseLimitOrderParam);
		
		// Req_LimitClosePosition
		socket.sendReqMsg(CTMWReqCommand.Req_LimitClosePosition, jsonReq);
	}
	
	/**
	 * 限价单撤单请求
	 */
	public void reqLimitRevoke(CXLimitRevokeParam cxLimitRevokeParam) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(cxLimitRevokeParam);
		
		// Req_LimitRevoke
		socket.sendReqMsg(CTMWReqCommand.Req_LimitRevoke, jsonReq);
	}
	
	
	/**
	 * 批量平市价单请求
	 */
	public void reqCloseMarketOrderMany(CXCloseMarketOrderManyParam cxCloseMarketOrderManyParam) {
		Gson gson = new Gson();
		String jsonReq = gson.toJson(cxCloseMarketOrderManyParam);
		
		// Req_CloseMarketOrderMany
		socket.sendReqMsg(CTMWReqCommand.Req_CloseMarketOrderMany, jsonReq);
	}
	
	
	/**
	 * 查询账户信息
	 */
	public void reqQryAccountInfo() {
		// ReqQry_AccountInfo
		socket.sendReqMsg(CTMWReqCommand.ReqQry_AccountInfo);
	}

	/**
	 * 请求查询商品信息
	 */
	public void reqQryCommodity() {
		// ReqQry_Commodity
		socket.sendReqMsg(CTMWReqCommand.ReqQry_Commodity);
	}
	
	/**
	 * 请求查询持仓单信息
	 */
	public void ReqQryPositionOrder() {
		// ReqQry_PositionOrder
		socket.sendReqMsg(CTMWReqCommand.ReqQry_PositionOrder);
	}
	
	/**
	 * 请求查询限价单信息
	 */
	public void reqQryLimitOrder() {
		// ReqQry_LimitOrder
		socket.sendReqMsg(CTMWReqCommand.ReqQry_LimitOrder);
	}
	
	/**
	 * 请求查询平仓单信息
	 */
	public void reqQryClosePosition() {
		// ReqQry_ClosePosition
		socket.sendReqMsg(CTMWReqCommand.ReqQry_ClosePosition);
	}
	
	/**
	 * 请求查询持仓单总量
	 */
	public void reqQryHoldPositionTotal() {
		// ReqQry_HoldPositionTotal
		socket.sendReqMsg(CTMWReqCommand.ReqQry_HoldPositionTotal);
	}
	
	/**
	 * 请求查询市场状态
	 */
	public void reqQryMarketStatus() {
		// ReqQry_MarketStatus
		socket.sendReqMsg(CTMWReqCommand.ReqQry_MarketStatus);
	}
	
	/**
	 * 根据持仓单ID，获取持仓单信息
	 */
	public void reqQryHoldPositionByID(long nHoldPositionID) {
		Map<String,Long> param= new HashMap<String,Long>();
		param.put("nHoldPositionID", nHoldPositionID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_HoldPositionByID
		socket.sendReqMsg(CTMWReqCommand.ReqQry_HoldPositionByID, jsonReq);
	}
	
	/**
	 * 根据限价单ID，获取限价单信息
	 */
	public void reqQryLimitOrderByID(long nLimitOrderID) {
		Map<String,Long> param= new HashMap<String,Long>();
		param.put("nLimitOrderID", nLimitOrderID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_LimitOrderByID
		socket.sendReqMsg(CTMWReqCommand.ReqQry_LimitOrderByID, jsonReq);
	}
	
	/**
	 * 根据平仓单ID，获取平仓信息
	 */
	public void reqQryClosePositionByID(long nClosePositionID) {
		Map<String,Long> param= new HashMap<String,Long>();
		param.put("nClosePositionID", nClosePositionID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_ClosePositionByID
		socket.sendReqMsg(CTMWReqCommand.ReqQry_ClosePositionByID, jsonReq);
	}
	
	/**
	 * 根据商品ID，获取持仓汇总信息
	 * @param nOpenDirector：建仓方向ID。
	 */
	public void reqQryHoldPositionTotalByCommodityID(int nCommodityID, int nOpenDirector) {
		Map<String,Integer> param= new HashMap<String,Integer>();
		param.put("nCommodityID", nCommodityID);
		param.put("nOpenDirector", nOpenDirector);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_HoldPositionTotalByCommodityID
		socket.sendReqMsg(CTMWReqCommand.ReqQry_HoldPositionTotalByCommodityID, jsonReq);
	}
	
	
	/**
	 * 根据商品ID，获取实时行情
	 */
	public void reqQryCommodityQuote(int nCommodityID) {
		Map<String,Integer> param= new HashMap<String,Integer>();
		param.put("nCommodityID", nCommodityID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_CommodityQuote
		socket.sendReqMsg(CTMWReqCommand.ReqQry_CommodityQuote, jsonReq);
	}
	
	
	/**
	 * 根据商品ID，获取其市价建仓的配置信息
	 */
	public void reqQryOpenMarketOrderConf(int nCommodityID) {
		Map<String,Integer> param= new HashMap<String,Integer>();
		param.put("nCommodityID", nCommodityID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_OpenMarketOrderConf
		socket.sendReqMsg(CTMWReqCommand.ReqQry_OpenMarketOrderConf, jsonReq);
	}
	
	/**
	 * 根据商品ID，获取其限价建仓的配置信息
	 */
	public void reqQryOpenLimitOrderConf(int nCommodityID) {
		Map<String,Integer> param= new HashMap<String,Integer>();
		param.put("nCommodityID", nCommodityID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_OpenLimitOrderConf
		socket.sendReqMsg(CTMWReqCommand.ReqQry_OpenLimitOrderConf, jsonReq);
	}
	
	/**
	 * 根据商品ID，获取其市价平仓的配置信息
	 */
	public void reqQryCloseMarketOrderConf(int nCommodityID) {
		Map<String,Integer> param= new HashMap<String,Integer>();
		param.put("nCommodityID", nCommodityID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_CloseMarketOrderConf
		socket.sendReqMsg(CTMWReqCommand.ReqQry_CloseMarketOrderConf, jsonReq);
	}
	
	/**
	 * 根据商品ID，获取限价平仓的配置信息
	 */
	public void reqQryLimitClosePositionConf(int nCommodityID) {
		Map<String,Integer> param= new HashMap<String,Integer>();
		param.put("nCommodityID", nCommodityID);
		
		Gson gson = new Gson();
		String jsonReq = gson.toJson(param);
		
		// ReqQry_LimitClosePositionConf
		socket.sendReqMsg(CTMWReqCommand.ReqQry_LimitClosePositionConf, jsonReq);
	}
}
