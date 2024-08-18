class Solution {
public:
    void permuteHelper(vector<int>& nums,int idx,vector<vector<int>> &res){
        if(idx == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for(int nextidx = idx;nextidx < nums.size();nextidx++){
            swap(nums[idx],nums[nextidx]);
            permuteHelper(nums,idx+1,res);
            swap(nums[idx],nums[nextidx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteHelper(nums,0,res);
        return res;
    }
};