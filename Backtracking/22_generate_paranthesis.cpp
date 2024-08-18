class Solution {
public:
    void generateParenthesisRecur(int n,int open,int close,vector<char> &tmp,vector<string> &res){
        if(open ==n and close==n){
            string currRes(tmp.begin(),tmp.end());
            res.push_back(currRes);
        }
        if(open<n){
            tmp.push_back('(');
            generateParenthesisRecur(n,open+1,close,tmp,res);
            tmp.pop_back();
        }
        if(close<open){
            tmp.push_back(')');
            generateParenthesisRecur(n,open,close+1,tmp,res);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res; vector<char> temp;
        generateParenthesisRecur(n,0,0,temp,res);
        return res;
    }
};