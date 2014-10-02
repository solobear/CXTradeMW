#include <windows.h> 

//���ӿ��� 
class IMyLock
{
public:
	virtual ~IMyLock() {}
	virtual void Lock() const = 0;
	virtual void Unlock() const = 0;
};


//����������� 
class Mutex : public IMyLock
{
public:
	Mutex();
	~Mutex();
	virtual void Lock() const;
	virtual void Unlock() const;
private:
	HANDLE m_mutex;
};
