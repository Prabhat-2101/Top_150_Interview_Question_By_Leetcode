/*
Approach: 
> Find total Sum of the array.
> Find maximum_subarray_sum without circular case using Kadane's Algorithm.
> Find minimum_subarray_sum without circular case using Kadane's Algorithm.
> Handle One edge case when all integers are negative then return the maximum negative value.
> At last, return the maximum of maximum_subarray_sum and total - minimum_subarray_sum.
*/


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_=INT_MAX,max_=INT_MIN,curr=0;
        int tsum1=0,tsum2=0,total=0;
        int countNeg=0,maxNeg=INT_MIN;
        for(const int it: nums){
            total += it;tsum1 += it;tsum2 += it;
            max_ = max(max_ , tsum1);
            min_ = min(min_ , tsum2);
            if(it < 0) {
                countNeg += 1;
                maxNeg = max(maxNeg,it);
            }
            if(tsum1 < 0) tsum1 = 0;
            if(tsum2 > 0) tsum2 = 0;
        }
        if(countNeg==nums.size()) return maxNeg;
        return max(max_,total-min_);
    }
};