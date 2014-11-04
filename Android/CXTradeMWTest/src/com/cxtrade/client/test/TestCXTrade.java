package com.cxtrade.client.test;

import android.test.ActivityInstrumentationTestCase2;

import com.cxtrade.client.MainActivity;
import com.cxtrade.mw.client.utils.LogUtils;

public class TestCXTrade extends ActivityInstrumentationTestCase2<MainActivity> {
	private static LogUtils logger = LogUtils.getLog(TestCXTrade.class);

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
			logger.info(Thread.currentThread().getName() + " 线程运行开始!");
			Thread thread1 = new Thread(new MultiConnectionsThread());
			Thread thread2 = new Thread(new MultiConnectionsThread());
			thread1.start();
			sleep(2000);
			thread2.start();
			
			sleep(50000);
			logger.info(Thread.currentThread().getName() + " 线程运行结束!");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	/**
	 * Sleep
	 */
	private static void sleep(int ms) {
		try {
			Thread.sleep(ms);
		} catch (InterruptedException e) {
			logger.error(e.getMessage());
		}
	}

}
