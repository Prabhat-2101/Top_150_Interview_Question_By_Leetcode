class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int prev=0,start=0,end=1;
        vector<string> res;
        if(nums.size()<=0) return res;
        while(end<nums.size()){
            if(nums[prev]+1 != nums[end]){
                string out = to_string(nums[start]);
                if(start!=prev)  out += "->" + to_string(nums[prev]);
                res.push_back(out);
                start = prev + 1;
            }
            prev = prev + 1;
            end += 1;
        }
        string out = to_string(nums[start]); 
        if(start!=prev)  out += "->" + to_string(nums[prev]);
        res.push_back(out);
        return res;
    }
};