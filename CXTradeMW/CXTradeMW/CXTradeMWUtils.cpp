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

//����ļ����Ƿ���ڣ��������򴴽�֮  
//�ļ��д��ڷ��� 0  
//�ļ��д���ʧ�ܷ���-1  
//�ļ��д���ʧ�ܷ���1  
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
			return 1;//�ļ��д����ɹ�  
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