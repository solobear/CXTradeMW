package com.cxtrade.client.test;

import com.cxtrade.client.MainActivity;
import com.cxtrade.mw.client.CXTradeMWClient;
import com.cxtrade.mw.client.CXTradeMWSpi;
import com.cxtrade.mw.client.utils.LogUtils;

import android.test.ActivityInstrumentationTestCase2;

public class TestCXTrade extends ActivityInstrumentationTestCase2<MainActivity> {
	private static LogUtils logger = LogUtils.getLog(TestCXTrade.class);

	private String mwHost;
	private int mwPort;

	/**
	 * 
	 */
	public TestCXTrade() {
		super(null);
	}

	/*
	 * 
	 * 
	 * 
	 */
	protected void setUp() throws Exception {
		super.setUp();

		mwHost = "182.254.133.20";
		//mwHost = "10.0.2.2";
		mwPort = 7190;
	}

	/*
	 * 
	 * 
	 * 
	 */
	protected void tearDown() throws Exception {
		super.tearDown();
	}

	/**
	 * 
	 */
	public void testCXMWClient() {

		try {
			logger.info("--连接中间件1");
			CXTradeMWSpi spi = new CXTradeMWSpiImpl();
			CXTradeMWClient client = new CXTradeMWClient(spi);
			client.connect(mwHost, mwPort); 
			
			logger.info("--登陆1");
			client.login("003098765432105", "123456");

			sleep(5000);
			logger.info("--账户信息1");
			client.reqQryMarketStatus();
			client.reqQryCommodity();
			client.reqQryAccountInfo();
			
			// 多登录
			sleep(10000);
			SyncClientsTest("003098765432103", "123456");
			
			sleep(5000);
			client.close();

			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	
	/**
	 * @param pass 
	 * @param user 
	 * 
	 */
	public void SyncClientsTest(String user, String pass) {

		try {
			logger.info("--连接中间件2");
			CXTradeMWSpi spi = new CXTradeMWSpiImpl();
			CXTradeMWClient client2 = new CXTradeMWClient(spi);
			client2.connect(mwHost, mwPort); 
			
			sleep(3000);
			logger.info("--登陆2");
			client2.login(user, pass);
			
			sleep(3000);
			logger.info("--账户信息2");
			client2.reqQryMarketStatus();
			client2.reqQryCommodity();
			client2.reqQryAccountInfo();
			
			sleep(30000);
			client2.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	/**
	 * Sleep
	 */
	private void sleep(int ms) {
		try {
			Thread.sleep(ms);
		} catch (InterruptedException e) {
			logger.error(e.getMessage());
		}
	}
}
