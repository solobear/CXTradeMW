#pragma once
#include "afxsock.h"
#include <stdio.h> 
#include <direct.h> 


//此类
class CXUtils
{
public:
	///
	static void CleanSlash(char *str);

	///
	static void PrintCurrentDir();

	/// 检查文件夹是否存在，不存在则创建之 
	static int CheckDir(char* dir);
};