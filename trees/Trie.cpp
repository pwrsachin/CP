//Interview Bit
#include<bits/stdc++.h>
using namespace std;

typedef struct TrieNode{
  struct TrieNode *child[26];
  bool isend;
}TrieNode;

TrieNode* getNode(){
    TrieNode *tmp = new TrieNode;
    for(int i=0;i<26;i++){
        tmp->child[i] = NULL;
    }
    tmp->isend = false;
    return tmp;
}

void add(TrieNode *root,string key){
    TrieNode *tmp = root;
    for(int i=0;i<key.size();i++){
        int ind = key[i]-'a';
        if(!tmp->child[ind]){
            tmp->child[ind] = getNode();
        }
        tmp = tmp->child[ind];
    }
    tmp->isend = true;
}

bool search(TrieNode *root,string key){
    TrieNode *tmp = root;
    for(int i=0;i<key.size();i++){
        int ind = key[i] - 'a';
        if(!tmp->child[ind]){
            return false;
        }
        tmp = tmp->child[ind];
    }
    return (tmp!=NULL && tmp->isend);
}

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second; 
    }
    return a.first>b.first;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    
    TrieNode *root = getNode();
    string word = "";
    for(auto it:A){
        if(it=='_' && word!=""){
            add(root,word);
            word = "";
        }
        else{
            word += it;
        }
    }
    if(word!="") add(root,word);
    vector< pair<int,int> > p;
    
    for(int i=0;i<B.size();i++){
        string word = "";
        int cnt = 0;
        for(auto it:B[i]){
            if(it=='_' && word!=""){
                //cout<<word<<" "<<search(root,word)<<"\n";
                if(search(root,word)) cnt++;
                word = "";
            }
            else{
                word += it;
            }
        }
        if(word!="" && search(root,word)) cnt++;
        //cout<<"\n";
        //cout<<i<<" "<<cnt<<"\n";
        p.push_back(make_pair(cnt,i));
    }
    
    sort(p.begin(),p.end(),cmp);
    vector<int> ans;
    for(auto it:p){
        ans.push_back(it.second);
    }
    return ans;
}
