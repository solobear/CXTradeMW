package com.cxtrade.client.test;

import com.cxtrade.client.MainActivity;
import com.cxtrade.mw.client.CXTradeMWClient;
import com.cxtrade.mw.client.CXTradeMWSpi;
import com.cxtrade.mw.client.utils.LogUtils;

import android.test.ActivityInstrumentationTestCase2;

public class TestCXTrade extends ActivityInstrumentationTestCase2<MainActivity> {
	private static LogUtils logger = LogUtils.getLog(TestCXTrade.class);

	private CXTradeMWClient client;

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

		logger.info("--连接中间件");
		CXTradeMWSpi spi = new CXTradeMWSpiImpl();
		client = new CXTradeMWClient(spi);
		client.connect("182.254.133.20", 7190); 
        //client.connect("10.0.2.2", 7190);//Localhost
	}

	/*
	 * 
	 * 
	 * 
	 */
	protected void tearDown() throws Exception {
		sleep(20000);
		client.close();

		super.tearDown();
	}

	/**
	 * 
	 */
	public void testCXMWClient() {

		logger.info("--登陆!");
		client.login("003098765432103", "123456");

		sleep(5000);
		
		logger.info("--账户信息!");
		client.reqQryCommodity();
		client.reqQryAccountInfo();
		sleep(5000);
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
