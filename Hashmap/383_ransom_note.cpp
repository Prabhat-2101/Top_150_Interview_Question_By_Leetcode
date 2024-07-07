#include<bits/stdc++.h>
using namespace std;

bool can_construct(string ransom, string magazine) {
    unordered_map<char,int> umap1,umap2;
    for(const char ch: ransom) umap1[ch]++;
    for(const char ch: magazine) umap2[ch]++;
    for(const auto it: umap1) if(umap2[it.first] < it.second) return false;
    return true;
}

int main(){
    string ransom,magazine;
    cin>>ransom>>magazine;

    bool result = can_construct(ransom,magazine);

    cout<<result<<endl;
}