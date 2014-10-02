package com.cxtrade.mw.client.beans;


/**
 * 登陆账号
 * @author Eric
 *
 */
public class CXLoginAccount {
	private String username;
	private String password;

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	/**
	 * @param username
	 * @param password
	 */
	public CXLoginAccount(String username, String password) {
		this.username = username;
		this.password = password;
	}
}
