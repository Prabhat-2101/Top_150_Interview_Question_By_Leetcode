#include<bits/stdc++.h>
using namespace std;

bool is_isomorphic(string s, string t) {
    vector<int> mp1(256,0),mp2(256,0);
    int size = s.size();
    for(int i=0;i<size;i++){
        if( mp1[s[i]] != mp2[t[i]] ) return false;
        mp1[s[i]] = i+1;
        mp2[t[i]] = i+1;
    }
    return true;
}

int main(){
    string first,second;
    cin>>first>>second;

    bool result = is_isomorphic(first,second);

    cout<<result<<endl;
}