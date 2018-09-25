#pragma once
//������
#ifndef UTILS_H
#define UTILS_H
#include "pch.h"
#include <fstream>
#include <iostream>
using namespace std;
//�ַ���ת������
int ByteToStr(element b, char str[ESIZE], int word = ESIZE)
{
	try
	{
		int base = 1;
		for (int i = word - 1; i >= 0; i--)
		{
			if (base&b)
				str[i] = '1';
			else
				str[i] = '0';
			base <<= 1;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int StrToByte(char str[ESIZE], element &b, int word = ESIZE)
{
	try
	{
		int base = 1;
		b = 0;
		for (int i = word - 1; i >= 0; i--)
		{
			if (str[i] == '1')
				b = base | b;
			//cout << "str to b " <<(int)b<<" "<<base<<" "<< str << endl;
			base <<= 1;
		}
		return 0;
	}
	catch (...)
	{
		cout << "��������" << str << " " << (int)b << endl;
		return -1;
	}
}


//�ļ���д
//��ȡ�ļ�
class IN
{
	fstream file;//�ļ�ָ��
	element buff[BUFFSIZE];//������
	int begin;//��ʼָ��
	int end;//����ָ��
	bool bad;//�ļ�״̬
	int Byte;
	//���»�����
	bool read(int size = BUFFSIZE)
	{
		file.read((char*)buff, size);
		begin = 0;
		end = file.gcount();//��ȡ��ȡ���ֽ���
		Byte += end;
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
		Byte = 0;
		if (!file.is_open())
		{
			std::cout << "�Ҳ����ļ�" << endl;
			bad = true;
		}
		else
			bad = false;
	}
	//��ȡһ�ֽ�
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
	int byteCount()
	{
		return Byte;
	}
	~IN()
	{
		file.close();
	}
};

class OUT
{
	fstream file;
	int Byte;
	bool bad;

	
public:

	OUT(const element FilePath[128])
	{
		file.open(FilePath, ios::binary | ios::out);
		Byte= 0;
		if (!file.is_open())
		{
			std::cout << "�Ҳ����ļ�" << endl;
			bad = true;
		}
		else
			bad = false;
	}
	//дһ��λ
	int operator()(char word[8])
	{
		if (bad) return -1;
		element b;
		StrToByte(word, b);
		//cout <<word<<":"<<(int)b<< endl;
		file.write(&b, 1);
		Byte += 8;
		return 1;
	}
	int word(char str[8])
	{
		element b;
		StrToByte(str, b);
		file.write(&b, 1);
		Byte += 8;
	}
	bool is()
	{
		return bad;
	}
	int byteCount()
	{
		return Byte;
	}
	~OUT()
	{
		file.close();
	}
};
#endif