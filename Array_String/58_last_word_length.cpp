#include<bits/stdc++.h>
using namespace std;
int last_word_legnth(string input){
    int len=0,flag=0;
    for(int i=input.length()-1;i>=0;i--){
        if(input[i]==' '){
            if(flag == 0) continue;
            else break;
        }else{ 
            flag = 1;
            len += 1;
        }
    }
    return len;
}
int main(){
    string input;cin>>input;
    
    int length = last_word_legnth(input);

    cout<<length<<endl;
}