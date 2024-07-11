#include<bits/stdc++.h>
using namespace std;

int my_sqrt(int x) {
    int start=0,end=x;
    long long int mid=(start+end)>>1;
    while(start<=end){
        long long int sq=mid*mid;
        if(sq==x) return mid;
        else if(sq>x) end=mid-1;
        else start=mid+1;
        mid=(start+end)>>1;
    }
    long long int res;
    res=(long long)start*(long long)start;
    if(res<x)
        return start;
    return start-1;
}

int main(){
    int num;cin>>num;

    int result = my_sqrt(num);

    cout<<result<<endl;
}