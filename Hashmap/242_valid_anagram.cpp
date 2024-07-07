#include<bits/stdc++.h>
using namespace std;
bool is_anagram(string s, string t) {
    unordered_map<char, int> count;
    
    for (auto x : s) count[x]++;
    for (auto x : t) count[x]--;
    for (auto x : count) if (x.second != 0) return false;
    
    return true;
}
int main(){
    string first,second;
    cin>>first>>second;

    bool result = is_anagram(first,second);

    cout<<result<<endl;
}