#include "pch.h"
#include "HaffCode.h"
#include"utils.h"

HaffCode::HaffCode()
{
}

bool HaffCode::initTree(const char path[128])
{
	codeChar(path);
	cout << "count over!" << endl;
	structTree();
	cout << "tree over!" << endl;
	initCodeMap(tree.size()-1);
	cout << "map over!" << endl;
	return true;
}

bool HaffCode::codeChar(const char path[128])
{
	int totle[256];
	memset(totle, 0, sizeof(totle));
	IN in(path);
	element c;
	while (in(c))
	{
		totle[c+OFFSET]++;
	}
	for (int i = 0; i < 256; i++)
	{
		if (totle[i] > 0)
		{
			code[i - OFFSET] = totle[i];
			tree.push_back(HaffNode((char)(i - OFFSET), totle[i]));
		}
	}
	return 1;
}

bool HaffCode::structTree()
{
	while (true)
	{
		int m1=-1, m2=-1;
		int size = tree.size();
		for (int i = 0; i < size; i++)
		{
			if (tree[i].parent == -1)
			{
				if (m1 == -1)
				{
					m1 = i;
				}
				else if(m2==-1)
				{
					if (tree[m1].weight < tree[i].weight)
						m2 = i;
					else
					{
						m2 = m1;
						m1 = i;
					}
				}
				else
				{
					if (tree[i].weight < tree[m1].weight)
						m1 = i;
					else if (tree[i].weight < tree[m2].weight)
						m2 = i;

				}
			}
		}
		cout << "m1:" << m1 << ",m2:" << m2 << ",size:" << size << endl;
		if (m2 == -1) break;
		tree[m1].parent= tree[m2].parent = tree.size();
		
		tree.push_back(HaffNode(-1, tree[m1].weight + tree[m2].weight, -1, m1, m2));
	}
	return true;
}

bool HaffCode::initCodeMap(int pos,string str)
{
	if (tree[pos].rc == -1)
	{
		code[tree[pos].val] = str;
		return true;
	}
	initCodeMap(tree[pos].lc, str + '0');
	initCodeMap(tree[pos].lc, str + '1');
	return true;
}



HaffCode::~HaffCode()
{
}
