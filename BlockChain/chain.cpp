#include "stdafx.h"
#include"chain.h"

Chain::Chain()
{
	Block tmp;
	tmp.PreHash = "";
	tmp.Data = "";
	tmp.Index = 0;
	tmp.TimeStamp = tmp.getTime();
	tmp.Hash = tmp.getHash();
	BlockChainTmp.push_back(tmp);
}

Chain::~Chain()
{

}

void Chain::addBlock(Block t)
{
	BlockChainTmp.push_back(t);
}


void Chain::output()
{
	for (auto x : BlockChainTmp)
	{
		cout << "---------------------\n"
			<< "There is the " << x.Index << " block :\n"
			<< "his PreHash :" << x.PreHash << endl
			<< "his TimeStamp :" << x.TimeStamp << endl
			<< "his hash: " << x.Hash << endl
			<< "his data: " << x.Data << endl;
	}
}















