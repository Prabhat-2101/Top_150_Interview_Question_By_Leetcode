#include<bits/stdc++.h>
using namespace std;

string reverse_string(string str) {
    string res="";
    stack<string> st;
    int i=0,n = str.length();
    while(i<n){
        string tmp = "";
        while(i<n && str[i]==' ')
            i += 1;
        while(i<n && str[i]!=' '){
            tmp += str[i];
            i += 1;
        }
        st.push(tmp);
    }
    while(!st.empty()){
        if(!res.empty()){
            res += " ";
        }
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    string input;getline(cin,input);
    
    string output = reverse_string(input);

    cout<<output<<endl;
}