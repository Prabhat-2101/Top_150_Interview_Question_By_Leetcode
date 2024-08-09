class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1 or nums[0]>nums[1]) return 0;
        int size = nums.size();
        if(nums[size-1] > nums[size-2]) return size-1;
        int low=0,high=size-2;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[mid+1]) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};