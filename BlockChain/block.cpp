#include "stdafx.h"
#include "block.h"
#include "md5.h"
#include<time.h>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>


Block::Block(int index, string prehash)
{
	Index = index;
	PreHash = prehash;
	TimeStamp = getTime();
	Hash = getHash();
}


string Block::getHash()
{
	string tmp;
	tmp = PreHash + Data + TimeStamp;               //综合上一个区块的hash，现在区块的Data，以及时间戳
	unsigned char *t = (unsigned char *)tmp.data(); //得到一个C类型的字符数组
	MD5 md5;
	md5.GenerateMD5(t, tmp.size());
	return md5.ToString();
}


void Block::input()
{
	string str;
	cout << "please input data: ";
	cin >> str;
	Data = str;
}

string Block::getTime()
{
	time_t t;
	tm *local;
	char buf[256];
	t = time(nullptr);        //get local time
	local = localtime(&t);
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S",local);  //change time format
	string time(buf);

	return time;

}




