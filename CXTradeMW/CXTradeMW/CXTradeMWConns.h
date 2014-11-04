#pragma once
#include <map> 
using namespace std;

class CXTradeMWConns
{
private:
	static CXTradeMWConns *m_pInstance;

	// ���캯����˽�е�
	CXTradeMWConns();

public:
	// Ψһ���
	static CXTradeMWConns* Instance();



private:
	// �������Ӵ���
	map<CString, int>  conn_Error_Map;

public:
	bool InBlackList(CString ipStr);
	void InsertIntoBlackList(CString ipStr);
};

