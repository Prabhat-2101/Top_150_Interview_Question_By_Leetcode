class Solution {
public:
    void combinationSumHelper(vector<int>& nums,int idx, int target,vector<int> &temp,vector<vector<int>>&res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(idx >= nums.size() or target < 0) {
            return;
        }
        temp.push_back(nums[idx]);
        combinationSumHelper(nums,idx,target-nums[idx],temp,res);
        temp.pop_back();
        combinationSumHelper(nums,idx+1,target,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; vector<int> temp;
        combinationSumHelper(nums,0,target,temp,res);
        return res;
    }
};