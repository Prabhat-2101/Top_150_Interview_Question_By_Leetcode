class Solution {
public:
    int count_solution = 0;
    bool is_safe(int row,int col,vector<vector<int>> &board){
        for(int j=0;j<=col;j++){
            if(board[row][j] == 1)
                return false;
        }
        for(int i=0;i<=row;i++){
            if(board[i][col] == 1)
                return false;
        }
        int j=col;
        for(int i=row;i>=0&&j>=0;i--,j--){
            if(board[i][j] == 1)
                return false;
        }
        j = col;
        for(int i=row;i<board.size()&&j>=0;i++,j--){
            if(board[i][j] == 1)
                return false;
        }
        return true;
    }

    void find_solution(int col,vector<vector<int>> &board,int N){
        if(col == N){
            count_solution++;
            return;
        }
        for(int i=0;i<board.size();i++){
            if(is_safe(i,col,board)){
                board[i][col] = 1;
                find_solution(col+1,board,N);
                board[i][col] = 0;
            }
        }
    }
    int totalNQueens(int N) {
        vector<vector<int>> board(N,vector<int>(N,0));
        find_solution(0,board,N);
        return count_solution;
    }
};