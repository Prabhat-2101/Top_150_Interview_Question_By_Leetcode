class Solution {
public:
    void combineHelper(int start,int n,int k,vector<vector<int>> &result,vector<int> &temp){
        if(start > n and temp.size()==k){
            result.push_back(temp);
            return;
        }
        if(start > n) return;
        temp.push_back(start);
        combineHelper(start + 1,n,k,result,temp);
        temp.pop_back();
        combineHelper(start + 1,n,k,result,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;vector<int> temp;
        combineHelper(1,n,k,result,temp);
        return result;
    }
};