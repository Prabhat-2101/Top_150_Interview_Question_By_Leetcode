#include<bits/stdc++.h>
using namespace std;

int find_single_ii(vector<int>& nums) {
    int ans = 0;
    for(int bit = 0; bit < 32; bit++){
        int count = 0;
        for(auto i : nums){
            if(i & (1<<bit)){
                count++;
            }
        }
        if(count % 3 == 1){
            ans = ans|(1<<bit); 
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];


    int single = find_single_ii(arr);

    cout<<single<<endl;

    return 0;
}