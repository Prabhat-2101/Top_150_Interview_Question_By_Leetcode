#include<bits/stdc++.h>
using namespace std;

void rotate_array(vector<int>& nums,int k) {
    int size = nums.size();
    k %= size;

    /*Rotate Using Built In Function*/
    /*std::rotate(nums.begin(),nums.begin()+(size-k),nums.end()); */
    
    /*Rotate Using Additional Space*/
    /* vector<int> res;
    int first = 0,sec = size-k;
    while(sec<size){res.push_back(nums[sec++]);}
    while(first<size-k) {res.push_back(nums[first++]);}
    nums = res; */

    /*Optimized : first reverse full array, then 0-K , then K-N*/
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int k;cin>>k;

    rotate_array(arr,k);

    cout<<"Resultant Array: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}