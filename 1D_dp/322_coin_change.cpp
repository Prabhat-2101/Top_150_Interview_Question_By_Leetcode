class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        if(amount==0) return 0;
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(const int it: coins){
                if(i>=it) {
                    dp[i] = min(dp[i],1 + dp[i - it]);
                }
            }
        }
        return dp[amount]==amount+1? -1: dp[amount];
    }
};