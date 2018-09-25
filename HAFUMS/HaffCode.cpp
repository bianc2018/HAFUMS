#include "pch.h"
#include "HaffCode.h"
#include"utils.h"

HaffCode::HaffCode()
{
}

bool HaffCode::initTree(const char path[256])
{
		int totle[128];
		memset(totle, 0, sizeof(totle));
		IN in(path);
		element c;
		while (in(c))
		{
			if (c <= 0 || c > 128)
				cout << "´íÎóµÄÊýÖµ" << int(c) << endl;
			totle[c]++;

		}
		for (int i = 0; i < 128; i++)
		{
			if (totle[i] > 0)
				cout << i << ":" << totle[i] << endl;
		}
		return 1;

}


HaffCode::~HaffCode()
{
}
