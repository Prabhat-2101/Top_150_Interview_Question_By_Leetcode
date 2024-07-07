#include<bits/stdc++.h>
using namespace std;

uint32_t reverse_bits(uint32_t n) {
    uint32_t ans = 0;
    for(int i = 0; i < 32 ; ++i){
        ans <<= 1;
         ans |=  (n&1) ;
         n >>= 1;
    }
    return ans ; 
}

int main(){
    uint32_t num;cin>>num;

    uint32_t result = reverse_bits(num);

    cout<<result<<endl;
}