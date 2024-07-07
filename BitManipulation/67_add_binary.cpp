#include<bits/stdc++.h>
using namespace std;

string add_binary(string a, string b) {
    int carry = 0;
    int l1 = a.length();
    int l2 = b.length();
    int i=0,j=0;
    string ans = "";
    while(i<l1 || j<l2 || carry){
        int num1=0,num2=0;
        if(i<l1 && a[l1-i-1]=='1')
            num1 = 1;
        if(j<l2 && b[l2-j-1]=='1')
            num2 = 1;
        int sum = num1+num2+carry;
        ans = to_string(sum%2)+ans;
        carry = sum/2;
        i++;j++;
    }
    return ans;
}

int main(){
    string first,second;
    cin>>first>>second;

    string result = add_binary(first,second);

    cout<<result<<endl;
}