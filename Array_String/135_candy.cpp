#include<bits/stdc++.h>
using namespace std;

int minimum_candy(vector<int> &ratings,int size){
    vector<int> candy_count(ratings.size(),1);
    for(int i=0;i<size-1;i++){
        if(ratings[i+1]>ratings[i]) candy_count[i+1] = candy_count[i] + 1;
    }
    for(int i=size-1;i>0;i--){
        if(ratings[i-1]>ratings[i] && candy_count[i-1]<=candy_count[i]) 
            candy_count[i-1] = candy_count[i] + 1;
    }
    for(const int it: candy_count) {
        total+=it;
    }
    return total;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = minimum_candy(arr,n);

    cout<<"Minimum Candy: "<<index<<endl;
}