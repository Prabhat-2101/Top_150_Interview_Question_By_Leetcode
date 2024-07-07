#include<bits/stdc++.h>
using namespace std;

int find_h_index(vector<int> &cite){
    sort(cite.begin(),cite.end());
    int size = cite.size();
    int low = 0,high = size-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(cite[mid] == (size-mid)) return cite[mid];
        if(cite[mid] > (size-mid)) high = mid-1;
        else low = mid+1;
    }
    return size-low;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = find_h_index(arr);

    cout<<"H Index: "<<index<<endl;
}