#pragma once
#include "afxsock.h"
#include <stdio.h> 
#include <direct.h> 


//����
class CXUtils
{
public:
	///
	static void CleanSlash(char *str);

	///
	static void PrintCurrentDir();

	/// ����ļ����Ƿ���ڣ��������򴴽�֮ 
	static int CheckDir(char* dir);
};