
/*
Approach:
> Add current element to temporary sum.
> Compare maximum sum.
> if temporary sum is negative then reset it to zero.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0],sum = 0;
        for(const int it: nums){
            sum += it;
            max_sum = max(max_sum,sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return max_sum;
    }
};