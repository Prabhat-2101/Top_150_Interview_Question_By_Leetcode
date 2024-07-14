class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++){
                swap(mat[i][j] ,mat[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col/2;j++){
                swap(mat[i][j],mat[i][col-j-1]);
            }
        }
    }
};