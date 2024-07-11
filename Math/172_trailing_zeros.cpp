#include<bits/stdc++.h>
using namespace std;

int count_trailing_zeroes(int n) {
    int count=0;
    while(n>0){
        count += n/5;
        n /= 5;
    }
    return count;
}

int main(){
    int num;cin>>num;

    int result = count_trailing_zeroes(num);

    cout<<result<<endl;
}