class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int i=0,j=size-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target) return {i+1,j+1};
            if(sum>target) {
                j -= 1;
            }else{
                i += 1;
            }
        }
        return {-1,-1};
    }
};