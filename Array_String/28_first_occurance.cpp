#include<bits/stdc++.h>
using namespace std;

int find_first_occurance(string h, string n) {
        int m = h.length();
        int o = n.length();
        if(o>m) return -1;
        for(int i=0;i<=m-o;i++){
            int flag = 1;
            for(int j=0;j<o;j++) if(h[i+j]!=n[j]) flag = 0;
            if(flag == 1) return i;
        }
        return -1;
    }

int main(){
    string haystack;cin>>haystack;
    string needle>>cin>>needle;
    int integer = find_first_occurance(haystack,needle);

    cout<<"Integer: "<<integer<<endl;
}