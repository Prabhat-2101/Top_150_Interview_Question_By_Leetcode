class Solution {
public:
    bool wordBreakRecur(string s,vector<string> &wordDict,int idx){
        if(idx == s.length()) return true;
        string temp = "";
        for(int j=idx;j<s.length();j++){
            temp += s[j];
            if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end()){
                if(wordBreakRecur(s,wordDict,j+1)) return true;
            }
        }
        return false;
    }
    int wordBreakMemo(string s,vector<string> &wordDict,int idx,vector<int> &dp){
        if(idx == s.length()) return true;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";   
        for(int j=idx;j<s.length();j++){
            temp += s[j];
            if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end()){
                if(wordBreakRecur(s,wordDict,j+1)) return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1,false);
        dp[0] = true;
        for(int end=1;end<=s.length();end++){
            for(const string word: wordDict){
                int start = end - word.length();
                if(start>=0 && dp[start]==true && s.substr(start,word.length()) == word) {
                    dp[end] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};