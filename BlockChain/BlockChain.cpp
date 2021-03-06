// BlockChain.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "block.h"
#include "chain.h"
#include "md5.h"
using namespace std;



int main()
{
	Chain BlockChain;
	int index;
	int flag = 5;

	string str, preHash;
	while (flag--)
	{
		auto it = BlockChain.BlockChainTmp.end();
		index = it[-1].Index + 1;
		preHash = it[-1].Hash;
		Block t(index, preHash);
		t.input();
		BlockChain.addBlock(t);
	}

	BlockChain.output();
    return 0;
}

