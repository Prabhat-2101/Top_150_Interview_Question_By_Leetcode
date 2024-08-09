class Solution {
public:
    int findUpperBound(vector<int>& nums, int target){
        int low=0,high=nums.size()-1; int idx = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else{
                idx = mid;
                low = mid + 1;
            }
        }
        return idx;
    }
    int findLowerBound(vector<int>& nums, int target){
        int low=0,high=nums.size()-1; int idx = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else{
                idx = mid;
                high = mid - 1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int upper = findUpperBound(nums,target);
        int lower = findLowerBound(nums,target);
        return {lower,upper};
    }
};