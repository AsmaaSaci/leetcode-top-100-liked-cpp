class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = backtrack(board, word, index + 1, i + 1, j) ||
                     backtrack(board, word, index + 1, i - 1, j) ||
                     backtrack(board, word, index + 1, i, j + 1) ||
                     backtrack(board, word, index + 1, i, j - 1);
        board[i][j] = temp;
        return found;
    }
};
