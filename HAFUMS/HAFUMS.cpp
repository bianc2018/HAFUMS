// HAFUMS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "HaffCode.h"
#include <iostream>
#define PATH  "./1.txt"
int main()
{
	HaffCode hc;
	hc.initTree(PATH);
	system("pause");

}
