#include<bits/stdc++.h>
using namespace std;

vector<int> plus_one(vector<int>& digits) {
    int carry = 0;
    for(int i=digits.size()-1;i>=0;i--){
        digits[i] += 1;
        carry = digits[i]/10;
        digits[i] %= 10;
        if(carry==0) break;
    }
    if(carry==1) digits.insert(digits.begin(),1,1);
    return digits;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];


    vector<int> digits = plus_one(arr);

    for(const int it: digits) cout<<it;

    return 0;
}