// HAFUMS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "utils.h"
#include <iostream>
#define PATH  "./1.txt"
int main()
{
	OUT out(PATH);
	char s[10] = "123456789";
	for (int i = 0; i < 9; i++)
	{
		char word[8];
		ByteToStr(s[i], word);

		for (int j = 0; j < 8; j++)
			out(word[j]);
	}
	system("pause");
}
