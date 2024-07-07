#include<bits/stdc++.h>
using namespace std;

string longest_common_prefix(vector<string>& str) {
    string out = "";
    int idx = 0,size=str.size();
    for(int i=0;i<str[0].length();i++){
        char ch = str[0][i];
        int count = 0;
        for(int j=1;j<size;j++){
            if(str[j][idx] == ch){
                count++;
            }
        }
        if(count == size-1){
            out+=ch;
            idx++;
        }
        else{
            break;
        }
    }
    return out;
}

int main(){
    int num;cin>>num;

    vector<string> string(num);

    for(int i=0;i<num;i++) cin>>string[i];

    string index = longest_common_prefix(string);

    cout<<"Longest Prefix: "<<index<<endl;

    return 0;
}