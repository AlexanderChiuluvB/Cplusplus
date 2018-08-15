#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct MinHeapNode{
    //character
    char data;
    //frequency of the character
    int freq;
    //left and right child
    MinHeapNode *left,*right;

    MinHeapNode(char data,int freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};

struct compare{
    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l->freq>r->freq);
    }

};

void printCodes(struct MinHeapNode *root,string str){
    if(!root)
        return;
    if(root->data!='$')
        cout<<root->data<<":"<<str<<endl;
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}


//
void huffManTreeNodes(char words[],int freq[],int size){

    struct MinHeapNode *left,*right,*top;
    //construct a min heap using priority queue

    //priority_queue is a container adapter
    //the first param is the data type stores in the queue;
    //the second param is the container vector or deque;
    //the third param is operator() usually we need to reload it according to the specfic data types
    //default compare is less , where the largest element will be on the top
    // here we reload the operator() as > so the smallest one will be on the top

    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;

    for(int i=0;i<size;i++)
    {
        minHeap.push(new MinHeapNode(words[i],freq[i]));

    }

   while(minHeap.size()!=1){

        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$',left->data+right->data);
        top->left=left;
        top->right=right;
        minHeap.push(top);

    }

    printCodes(minHeap.top(),"");
}


int main() {
    char words[] = {'a','b','c','d','e'};
    int freq[] = {15,23,42,11,2};
    int size = sizeof(words)/sizeof(words[0]);

    huffManTreeNodes(words,freq,size);

    return 0;
}