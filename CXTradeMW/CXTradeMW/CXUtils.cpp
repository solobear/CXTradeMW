#pragma once
#include "CXUtils.h"

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