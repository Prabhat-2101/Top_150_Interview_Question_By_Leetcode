#include<bits/stdc++.h>
using namespace std;

int next_number(int n){
    int newNumber = 0;
    while(n!=0){
        int num = n%10;
        newNumber += num*num;
        n = n/10;
    }
    return newNumber;
}

bool check_happy(int n) {
    unordered_set<int> set;
    while(n!=1 && !set.count(n)){
        set.insert(n);
        n = next_number(n);
    }
    return n==1;
}

int main(){
    int n;cin>>n;
    
    bool is_happy = check_happy(n);

    cout<<is_happy<<endl;

    return 0;
}