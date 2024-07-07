#include<bits/stdc++.h>
using namespace std;

int maximum_water_trapping(vector<int> &height){
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);
    int left_max = INT_MIN, right_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        left_max = max(height[i], left_max);
        leftMax[i] = (left_max);
    }
    for (int i = n - 1; i >= 0; i--) {
        right_max = max(right_max, height[i]);
        rightMax[i] = (right_max);
    }
    int trapWater = 0;
    for (int i = 0; i < n; i++) {
        trapWater += min(leftMax[i], rightMax[i]) - height[i];
    }
    return trapWater;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = maximum_water_trapping(arr);

    cout<<"Minimum Candy: "<<index<<endl;
}