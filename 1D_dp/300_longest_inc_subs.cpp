class Solution {
public:
    int LISusingTabulatiion(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int max_len = 1;
        for(int i=1;i<nums.size();i++){
            int max_prev = 0;
            for(int j=i-1;j>=0;j--){
                if(nums[j] < nums[i]) max_prev = max(max_prev,dp[j]);
            }
            dp[i] = 1 + max_prev;
            max_len = max(max_len,dp[i]);
        }
        return max_len;
    }
    int lengthOfLIS(vector<int>& nums){
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(temp.back() < nums[i]) {
                temp.push_back(nums[i]);
            }else{
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};