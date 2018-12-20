

class TrieNode{
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        memset(next,0,sizeof(next));
    }
};

class Solution {
public:
    TrieNode*root = new TrieNode();
    
    void insert(string word){
        TrieNode* p = root;
        int size = word.size();
        for(int i=0;i<size;i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a'] = new TrieNode();
            }
            p = p->next[word[i]-'a'];
        }
        p->isWord = true;
    }
    
    string search(string word){
        TrieNode *p = root;
        int size = word.size();
        string s;
        for(int i=0;i<size;i++){
            if(p->next[word[i]-'a']==NULL){
                break;
            }
             p = p->next[word[i]-'a'];
            s+=word[i];
            if(p->isWord)
                return s;
        }
        return word;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        
        stringstream ss(sentence);
        string word,result;
        int dictSize = dict.size();
        int wordCount=0;
        vector<string>wordVec;
        for(auto str:dict){
            insert(str);
        }
        while(ss>>word){
            wordVec.push_back(word);
        }
        wordCount=wordVec.size();
        int i=0;
        for(auto str:wordVec){
            result+=search(str);
            if(i<wordCount-1){
                result+=" ";
            }
            i++;
        }
        return result;   
    }    
};