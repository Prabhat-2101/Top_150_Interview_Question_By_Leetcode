#include<bits/stdc++.h>
using namespace std;

int longest_consecutive(vector<int>& nums) {
    unordered_map<int,bool> umap;
    
    for(const int num: nums) umap[num] = true;

    for(const int num: nums) if(umap.count(num-1)) umap[num] = false;

    int max_len = 0;
    for(const int num: nums){
        if(umap[num]) {
            int count = 0,next_num = num;
            while(umap.count(next_num)){
                count += 1;
                next_num += 1;
            }
            max_len = max(max_len,count);
        }
    }
    return max_len;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = longest_consecutive(arr);

    cout<<index<<endl;

    return 0;
}