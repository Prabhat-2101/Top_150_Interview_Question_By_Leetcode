#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int x) {
    string number = std::to_string(x);
    int j = number.size()-1;
    bool is_pal = true;
    for(int i = 0; i<j; i++){
        if(number[i]!=number[j]){
            is_pal=false;
            break;
        }
        else{
            j--;
        }
    }
    return is_pal;
}

int main(){
    int num;cin>>num;

    bool result = is_palindrome(num);

    cout<<result<<endl;
}