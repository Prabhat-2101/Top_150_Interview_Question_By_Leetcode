class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int idx = -1;
        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target){
                idx = i;
            }else{
                break;
            }
        }
        if(idx == -1)
            return false;
        for(int i=0;i<n;i++){
            if(matrix[idx][i] == target)
                return true;
        }
        return false;
    }
};