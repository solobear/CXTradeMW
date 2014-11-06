package com.cxtrade.mw.client;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

import com.cxtrade.mw.client.utils.LogUtils;
import com.cxtrade.mw.client.utils.MWStringUtils;
import com.google.gson.Gson;


/**
 * 中间件Socket连接
 * 
 * @author Eric
 * 
 */
class CXTradeMWSocket {
	private static LogUtils logger = LogUtils.getLog(CXTradeMWSocket.class);

	// CXTradeMWClient
	private CXTradeMWClient mwClient;
	
	// Socket Client
	private Socket client;
	
	private BufferedReader mReader;
	private PrintWriter mWriter;
	
	// 是否可以连接
	private boolean mCanReadSocekt = false;



	/**
	 * @param mwClient 
	 * @param address
	 * @param port
	 * @return 是否连接成功
	 * @throws Exception
	 */
	public CXTradeMWSocket(CXTradeMWClient mwClient, String address, int port) throws Exception {
		// mwClient
		this.mwClient = mwClient;
		
		// 连接
		logger.info("Connectting to : " + address + ":" + port);
		client = new Socket(address, port);
		logger.info("Socket Client created: " + address + ":" + port);

		// 读入
		mReader = new BufferedReader(new InputStreamReader(client.getInputStream(),"GBK"));

		// 输出
		mWriter = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);

		// 检查是否连接成功
		logger.info("Socket Client status = " + isConnected());
		mCanReadSocekt = isConnected();
		
		// 启动数据接收线程
		startListener();
	}

	/**
	 * 是否连通
	 * 
	 * @return
	 */
	private boolean isConnected() {
		return client.isConnected();
	}

	/**
	 * 启动数据接收线程
	 */
	private void startListener() {
		// 接收消息线程
		Runnable mReadSocketRunnable = new Runnable() {
			@Override
			public void run() {
				try {
					logger.info("启动数据读取线程。。。");
					while (mCanReadSocekt) {
						// 读数据
						String result = mReader.readLine();
						if (null == result || result.length() <= 1)
							continue;

						// 交给数据处理程序
						dispatchResponseJsonMsg(result);

						// 交给CPU选择
						Thread.sleep(0);
					}
					logger.info("数据读取线程关闭！");
				} catch (Exception e) {
					logger.error(e.getMessage());
				}
			}
		};

		// 启动线程
		new Thread(mReadSocketRunnable).start();
	}

	/**
	 * 发送消息
	 * @param commandID 
	 * @return
	 */
	public void sendReqMsg(int commandID) {
		sendReqMsg(commandID, null);
	}

	
	/**
	 * 发送消息
	 * @param commandID 
	 * @param reqMsg
	 * @return
	 */
	public void sendReqMsg(int commandID, String jSonReq) {
		// Map
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("commandID", commandID);
		if(!MWStringUtils.isNullOrEmpty(jSonReq)){
			map.put("jsonParams", jSonReq);
		}
		
		// 生成JsonReq
		Gson gson = new Gson();
		String jsonReq = gson.toJson(map);
		
		// 发送请求
		if(null != mWriter){
			mWriter.write(jsonReq);
			mWriter.flush();
		}
	}
	
	/**
	 * 收到消息
	 * 
	 * @param result
	 * @throws UnsupportedEncodingException 
	 */
	private void dispatchResponseJsonMsg(String responseJsonMsg) throws UnsupportedEncodingException {	 
		this.mwClient.dispatchResponseJsonMsg(responseJsonMsg);
	}

	/**
	 * 关闭连接
	 * 
	 * @throws Exception
	 */
	public void close() throws Exception {
		// 连接关闭
		mCanReadSocekt = false;

		// 关闭资源
		Exception ex = null;

		if (null != mWriter) {
			try {
				mWriter.close();
				mWriter = null;
			} catch (Exception e) {
				ex = e;
			}
		}

		if (null != mReader) {
			try {
				mReader.close();
				mReader = null;
			} catch (Exception e) {
				ex = e;
			}
		}

		if (null != client) {
			try {
				client.close();
				client = null;
			} catch (Exception e) {
				ex = e;
			}
		}

		// 跑出异常
		if (null != ex) {
			throw ex;
		}
		
		logger.info("中间件连接关闭！");
	}
}
