#pragma once
#ifndef _CHAIN_H
#define _CHAIN_H
#include <iostream>
#include "block.h"
#include <string>
#include <vector>
using namespace std;

class Chain
{
public:
	vector<Block> BlockChainTmp;  //use a vector to save block
	Chain(); //´´ÊÀÇø¿é
	~Chain();
	void addBlock(Block t);//add new block
	void output();//output chain node

};

#endif
