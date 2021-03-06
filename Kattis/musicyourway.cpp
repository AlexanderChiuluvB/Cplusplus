// KATTIS2.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int index=1;


bool compare (vector<string> lhs,vector<string> rhs){
	return lhs[index]<rhs[index];

}


int main() {

	vector<string> attributes;
	map<string,int> attributesMP;
	vector<vector<string> >descriptions;
	vector<string> sortCommands;
	string line,att,des,command;
	getline(cin,line);
	stringstream stream(line);
	int i=0;

	while(getline(stream,att,' ')){
		attributes.push_back(att);
		attributesMP[att] =i++;
	}

	int N;
	cin>>N;
	vector<string> tempVec;
	int arrNum = attributes.size();
	for(int i=0;i<N;i++){
		tempVec.clear();
		for(int j=0;j<arrNum;j++){
			string temp;
			cin>>temp;
			tempVec.push_back(temp);
		}
		descriptions.push_back(tempVec);
	}

	cin>>N;
	for(int i=0;i<N;i++){
		string comm;
		cin>>comm;
		index = attributesMP[comm];
		stable_sort(descriptions.begin(),descriptions.end(),compare);

		for(auto w:attributes){
			cout<<w<<" ";
		}
		cout<<endl;

		for(auto song:descriptions){

			for(auto property:song){
				cout<<property<<" ";
			}
			cout<<endl;

		}


	}









}