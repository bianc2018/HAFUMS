#pragma once
#include"utils.h"
struct HaffNode
{
	int val;
	int parent;
	int rc;
	int lc;
	int weight;
};
class HaffCode
{
public:
	HaffCode();

	~HaffCode();
};

