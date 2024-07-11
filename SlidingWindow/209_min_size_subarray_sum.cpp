class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int subarray_len = size+1, start=0,end=0;
        unsigned int sum = 0;
        while(end < size){
            sum += nums[end];
            if(sum>=target){
                subarray_len = min(subarray_len,end-start+1);
                while(sum>=target){
                    sum -= nums[start];
                    subarray_len = min(subarray_len,end-start+1);
                    start += 1;
                }
            }
            end += 1;
            cout<<subarray_len<<" ";
        }
        return (subarray_len==size+1) ? 0: subarray_len;
    }
};