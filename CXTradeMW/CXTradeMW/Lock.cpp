#include "Lock.h" 

//����һ������������� 
Mutex::Mutex()
{
	m_mutex = ::CreateMutex(NULL, FALSE, NULL);
}


//���ٻ�������ͷ���Դ 
Mutex::~Mutex()
{
	::CloseHandle(m_mutex);
}


//ȷ��ӵ�л��������̶߳Ա�������Դ�Ķ��Է��� 
void Mutex::Lock() const
{
	DWORD d = WaitForSingleObject(m_mutex, INFINITE);
}

//�ͷŵ�ǰ�߳�ӵ�еĻ��������ʹ�����߳̿���ӵ�л�����󣬶Ա�������Դ���з��� 
void Mutex::Unlock() const
{
	::ReleaseMutex(m_mutex);
}
