#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> group_anagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> ToAnagram;
    for(const string& s:strs){
      string key = s;
      ranges::sort(key);
      ToAnagram[key].push_back(s);
    }
    for(const auto& a:ToAnagram)
      ans.push_back(a.second);
    return ans;    
}

int main(){
    int n;cin>>n;

    vector<string> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<string>> result = group_anagrams(arr);

    for(const auto vec: result){
        for(const string str: vec) cout<<str<<" ";
        cout<<endl;
    }
}