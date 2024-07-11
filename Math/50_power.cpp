#include<bits/stdc++.h>
using namespace std;

double find_power(double x, int n) {
    if(n<0){
        n = abs(n);
        x = 1/x;
    }
    if(n==0) return 1;
    if(n==1) return x;
    if(n%2==0) return find_power(x*x,n/2);
    return x*find_power(x*x,n/2);
}

int main(){
    int num,power;cin>>num>>power;

    double result = find_power(num,power);

    cout<<result<<endl;

    return 0;
}