#include<bits/stdc++.h>
using namespace std;

vector<int> product_except_self(vector<int>& nums) {
    int size = nums.size(),zero_count = 0,prod_nonzero = 1;
    for(const int it: nums){
        if(it!=0) prod_nonzero *= it;
        else zero_count += 1;
    }
    if(zero_count>1){
        for(int i=0;i<size;i++){
            nums[i] = 0;
        }
    }else if(zero_count==1){
        for(int i=0;i<size;i++){
            if(nums[i]!=0) nums[i]=0;
            else nums[i] = prod_nonzero;
        }
    }else{
        for(int i=0;i<size;i++){
            nums[i] = prod_nonzero/nums[i];
        }
    }
    return nums;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    arr = product_except_self(arr);

    cout<<"Resultant Array: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}