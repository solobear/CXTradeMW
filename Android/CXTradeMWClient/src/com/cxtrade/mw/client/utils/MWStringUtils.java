package com.cxtrade.mw.client.utils;

/**
 * @author Eric
 *
 */
public class MWStringUtils {

	/**
	 * 是否为空
	 * @param str
	 * @return
	 */
	public static boolean isNullOrEmpty(String str) {
		if(str==null){
			return true;
		}else if(str.trim().equals("")){
			return true;
		}else{
			return false;
		}
	}



}
