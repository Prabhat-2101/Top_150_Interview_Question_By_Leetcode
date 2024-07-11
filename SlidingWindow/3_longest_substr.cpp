class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length<=1) return length;
        unordered_set<char> uset;
        int start = 0,end = 0, max_len = 0;
        while(end < length){
            if(uset.count(s[end])==0){
                uset.insert(s[end]);
                max_len = max(max_len,end-start + 1);
            }else{
                while(uset.count(s[end])){
                    uset.erase(s[start]);
                    start += 1;
                }
                uset.insert(s[end]);
            }
            end += 1;
        }
        return max_len;
    }
};