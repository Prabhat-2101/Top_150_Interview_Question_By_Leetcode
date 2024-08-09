class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int low=0,high=size-1;
        int min_val = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= nums[low]) {
                min_val = min(min_val,nums[low]);
                low = mid+1;
            }
            else {
                min_val = min(min_val,nums[mid]);
                high = mid-1;
            }
        }
        return min_val;
    }
};