#define vvc vector<vector<char>>
class Solution {
    private:
    vector<pair<int,int>> dirs{{0,+1},{0,-1},{+1,0},{-1,0}};
public:
    bool word_search_recur(vvc& board,int si,int sj,int idx, string word){
        if(idx == word.length()) {
            return true;
        }
        int m = board.size(),n = board[0].size();
        if (si >= m || sj >= n || si < 0 || sj < 0 || board[si][sj] != word[idx]) {
            return false;
        }
        char temp = board[si][sj];
        board[si][sj] = '#';
        bool nextSearch = word_search_recur(board, si + 1, sj, idx + 1, word) ||
                        word_search_recur(board, si - 1, sj, idx + 1, word) ||
                      word_search_recur(board, si, sj + 1, idx + 1, word) ||
                      word_search_recur(board, si, sj - 1, idx + 1, word);
        if(nextSearch) return true;
        board[si][sj] = temp;
        return false;
    }
    bool exist(vvc& board, string word) {
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) 
            if(word_search_recur(board,i,j,0,word)) return true;
        }
        return false;
    }
};