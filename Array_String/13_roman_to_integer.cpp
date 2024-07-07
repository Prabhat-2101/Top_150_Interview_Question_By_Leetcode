#include<bits/stdc++.h>
using namespace std;

int convert_roman_to_integer(string s){
    unordered_map<char,int> umap;
    umap['I']=1, umap['V']=5,umap['X']=10;
    umap['L']=50,umap['C']=100,umap['D']=500,umap['M']=1000;
    int total = 0,i = 0;
    while(i<s.length()){
        if(umap[s[i]]<umap[s[i+1]]){
            total += (umap[s[i+1]]-umap[s[i]]);
            i += 2;
        }else{
            total += umap[s[i]];
            i += 1;
        }
    }
    return total;
}

int main(){
    string number;cin>>number;

    int integer = convert_roman_to_integer(number);

    cout<<"Integer: "<<integer<<endl;
}