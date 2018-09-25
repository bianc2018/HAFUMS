#pragma once
#ifndef HAFFCODE_H
#define HAFFCODE_H
#include "pch.h"
#include <vector>
#include <map>
using namespace std;
struct Header
{
	char orgin[128];
	int size;
};
struct HaffNode
{
	char val;
	int parent;
	int rc;
	int lc;
	int weight;

	HaffNode(char _val, int _weight,int _parent=-1,int _rc=-1,int _lc=-1):val(_val),parent(_parent),rc(_rc),lc(_lc),weight(_weight)
	{}
};
//×ó0ÓÒ1
class HaffCode
{
	vector<HaffNode> tree;
	map<char, string> code;
public:
	HaffCode();
	//¹¹½¨¹ş·òÂüÊ÷£¬Óë±àÂëÓ³Éä
	bool initTree(const char path[128]);
	bool codeChar(const char path[128]);
	bool structTree();
	bool initCodeMap(int pos,string str="");
	~HaffCode();
};

#endif