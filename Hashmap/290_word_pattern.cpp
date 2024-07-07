#include<bits/stdc++.h>
using namespace std;

bool word_pattern(string pattern, string s) {
    vector<string> strs;
    stringstream ss(s); string word;
    while(ss>>word) strs.push_back(word);
    int m = pattern.length();
    int n = strs.size();
    if(m!=n) return false;
    unordered_map<string,char> umap1;
    unordered_map<char,string> umap2;
    for(int i=0;i<m;i++){
        if(umap1.find(strs[i]) != umap1.end() && umap1[strs[i]] != pattern[i]) return false;
        if(umap2.find(pattern[i]) != umap2.end() && umap2[pattern[i]] != strs[i]) return false;
        umap1[strs[i]] = pattern[i];
        umap2[pattern[i]] = strs[i];
    }
    return true;
}

int main(){
    string pattern,str;
    getline(cin,str); cin>>pattern;    
    bool result = word_pattern(pattern,str);

    cout<<result<<endl;
}