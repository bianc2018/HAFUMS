#pragma once
#ifndef HAFFCODE_H
#define HAFFCODE_H
#include "pch.h"
struct HaffNode
{
	char val;
	int parent;
	int rc;
	int lc;
	int weight;
};
class HaffCode
{
public:
	HaffCode();
	bool initTree(const char path[256]);
	~HaffCode();
};

#endif