#pragma once
#include "afxsock.h"
#include <stdio.h> 
#include <direct.h> 

//¥À¿‡
class CXUtils
{
public:
	///
	static void CleanSlash(char *str);

	///
	static void PrintCurrentDir();
};