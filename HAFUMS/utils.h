#pragma once
//工具类
#ifndef UTILS_H
#define UTILS_H
#include "pch.h"
#include <fstream>
#include <iostream>
using namespace std;
//文件读写

class IN
{
	fstream file;
	element buff[BUFFSIZE];
	int begin;
	int end;
	bool bad;

	bool read(int size = BUFFSIZE)
	{
		file.read((char*)buff, size);
		begin = 0;
		end = file.gcount();
		//cout << end << endl;
		if (end ==0) return false;
		return true;
	}
public:
	IN(const element FilePath[128])
	{
		file.open(FilePath,ios::binary|ios::in);
		begin = 0;
		end = 0;
		if (!file.is_open())
		{
			std::cout << "找不到文件" << endl;
			bad = true;
		}
		else
			bad = false;
	}
	
	int operator()(element&data)
	{
		if (bad) return -2;

		if (begin >= end)
			if (!read()) return -1;

		data = buff[begin++];
		return 1;
	}
	bool is()
	{
		return bad;
	}
	~IN()
	{
		file.close();
	}
};

class OUT
{

public:

};
#endif