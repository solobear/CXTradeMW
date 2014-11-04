#pragma once
#include <map> 
using namespace std;

class CXTradeMWConns
{
private:
	static CXTradeMWConns *m_pInstance;

	// 构造函数是私有的
	CXTradeMWConns();

public:
	// 唯一入口
	static CXTradeMWConns* Instance();



private:
	// 错误连接次数
	map<CString, int>  conn_Error_Map;

public:
	bool InBlackList(CString ipStr);
	void InsertIntoBlackList(CString ipStr);
};

