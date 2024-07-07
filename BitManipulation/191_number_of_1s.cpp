#include<bits/stdc++.h>
using namespace std;

int hamming_weight(int n){
    int count = 0;
    while(n>0){
        count += 1;
        n = n&(n-1);
    }
    return count;
}

int main(){
    int num;cin>>num;

    int result = hamming_weight(num);

    cout<<result<<endl;
}