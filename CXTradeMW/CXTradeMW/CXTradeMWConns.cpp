#include "stdafx.h"
#include "CXTradeMWConns.h"
#include "log4z.h"

using namespace zsummer::log4z;


// 初始化
CXTradeMWConns* CXTradeMWConns::m_pInstance = NULL;

// 构造函数是私有的
CXTradeMWConns::CXTradeMWConns()   
{

}

// 唯一入口
CXTradeMWConns* CXTradeMWConns::Instance()
{
	if (m_pInstance == NULL)  //判断是否第一次调用
		m_pInstance = new CXTradeMWConns();
	return m_pInstance;
}

// 是否黑名单
bool CXTradeMWConns::InBlackList(CString ipStr){
	if (conn_Error_Map[ipStr]>3){
		return true;
	}
	else{
		return false;
	}
}


// 加入黑名单
void CXTradeMWConns::InsertIntoBlackList(CString ipStr){
	int errorCount = conn_Error_Map[ipStr];
	conn_Error_Map[ipStr] = errorCount + 1;

	//LOGE(conn_Error_Map[ipStr] << "");
}