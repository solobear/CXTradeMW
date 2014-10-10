#pragma once
#include "CXTradeMWUtils.h"

///
void CXUtils::CleanSlash(char *str)
{
	char *copied;
	for (copied = str; *str; str++)
	{
		if (*str != '\\')
			*copied++ = *str;
	}
	*copied = 0x00;
	return;
}

///
void CXUtils::PrintCurrentDir(){
	char buffer[1024];
	_getcwd(buffer, 1024);
	printf("--Current Dir: %s\n", buffer);
}

//检查文件夹是否存在，不存在则创建之  
//文件夹存在返回 0  
//文件夹创建失败返回-1  
//文件夹创建失败返回1  
int CXUtils::CheckDir(char* dir)
{
	FILE *fp = NULL;
	char TempDir[200];
	memset(TempDir, '\0', sizeof(TempDir));
	sprintf_s(TempDir, dir);
	strcat_s(TempDir, "\\");
	strcat_s(TempDir, ".temp.fortest");

	fopen_s(&fp, TempDir, "w");
	if (!fp)
	{
		if (_mkdir(dir) == 0)
		{
			return 1;//文件夹创建成功  
		}
		else
		{
			return -1;//can not make a dir;  
		}
	}
	else
	{
		fclose(fp);
	}
	return 0;
}