#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <string>
using namespace std;


struct BlockHead
{
	string PreHash; //前一块的哈希
	string Data;    //简化操作，本应该为梅克尔树根哈希
	string TimeStamp; //时间戳
	int Index;        //索引
};

class Block :public BlockHead
{
public:
	int size;
	string Hash; //本区块区块头的哈希值
	Block() {}
	Block(int index, string preHash);
	string getHash();
	void input();
	string getTime();

};


#endif
#pragma once
