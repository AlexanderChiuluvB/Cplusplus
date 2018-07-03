#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <string>
using namespace std;


struct BlockHead
{
	string PreHash; //ǰһ��Ĺ�ϣ
	string Data;    //�򻯲�������Ӧ��Ϊ÷�˶�������ϣ
	string TimeStamp; //ʱ���
	int Index;        //����
};

class Block :public BlockHead
{
public:
	int size;
	string Hash; //����������ͷ�Ĺ�ϣֵ
	Block() {}
	Block(int index, string preHash);
	string getHash();
	void input();
	string getTime();

};


#endif
#pragma once
