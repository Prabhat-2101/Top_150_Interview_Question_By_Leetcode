#include<bits/stdc++.h>
using namespace std;

int remove_element(vector<int> &arr,int n,int val){
    int it = 0;
    for(int i=0;i<n;i++){
        if(arr[i] != val) {
            arr[it++] = arr[i];
        }
    }
    return it;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int val;cin>>val;

    int index = remove_element(arr,n,val);

    cout<<"Resultant Array: ";
    for(int i=0;i<index;i++) cout<<arr[i]<<" ";
}