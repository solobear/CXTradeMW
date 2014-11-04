#include "stdafx.h"
#include "CXTradeMWConns.h"
#include "log4z.h"

using namespace zsummer::log4z;


// ��ʼ��
CXTradeMWConns* CXTradeMWConns::m_pInstance = NULL;

// ���캯����˽�е�
CXTradeMWConns::CXTradeMWConns()   
{

}

// Ψһ���
CXTradeMWConns* CXTradeMWConns::Instance()
{
	if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
		m_pInstance = new CXTradeMWConns();
	return m_pInstance;
}

// �Ƿ������
bool CXTradeMWConns::InBlackList(CString ipStr){
	if (conn_Error_Map[ipStr]>3){
		return true;
	}
	else{
		return false;
	}
}


// ���������
void CXTradeMWConns::InsertIntoBlackList(CString ipStr){
	int errorCount = conn_Error_Map[ipStr];
	conn_Error_Map[ipStr] = errorCount + 1;

	//LOGE(conn_Error_Map[ipStr] << "");
}