#include<bits/stdc++.h>
using namespace std;

int bitwise_and(int left,int right) {
    int count = 0;
    while(left<right){
        left >>= 1;
        right >>= 1;
        count++;
    }
    return left<<count;
}

int main(){
    int left,right;cin>>left>>right;
    
    int result = bitwise_and(left,right);

    cout<<result<<endl;

    return 0;
}