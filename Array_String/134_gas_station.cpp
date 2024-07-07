#include<bits/stdc++.h>
using namespace std;

int find_start_point(vector<int> &gas,vector<int> &cost){
    int total =0, mid = 0,index = 0;
    for(int i = 0;i < gas.size();i++){
        total += (gas[i]-cost[i]);
        mid += (gas[i]-cost[i]);
        if(mid<0){
            mid = 0;
            index = i+1;
        }
    } 
    return total<0?-1:index;
}

int main(){
    int num;cin>>num;
    vector<int> gas(num),cost(num);

    for(int i=0;i<num;i++) cin>>gas[i];
    
    for(int i=0;i<num;i++) cin>>cost[i];

    int start = find_start_point(gas,cost);

    if(start==-1) cout<<"Can't Complete Circuit"<<endl;
    else cout<<"Start Point: "<<start<<endl;

    return 0;
}