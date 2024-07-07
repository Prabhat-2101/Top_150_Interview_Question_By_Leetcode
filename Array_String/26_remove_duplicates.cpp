#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> &arr,int n){
    int prev=0,next=1;
    while(next<n){
        if(arr[prev] != arr[next]){
            arr[++prev] = arr[next];
        }
        next += 1;
    }
    return prev+1;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = remove_duplicates(arr,n);

    cout<<"Resultant Array: ";
    for(int i=0;i<index;i++) cout<<arr[i]<<" ";
}