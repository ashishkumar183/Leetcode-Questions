class Solution {
public:
    int numberOfOnes(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        if (i > 0 && board[i - 1][j] == 1) {
            count++;
        }
        if (i > 0 && j > 0 && board[i - 1][j - 1] == 1) {
            count++;
        }
        if (i > 0 && j < board[0].size() - 1 && board[i - 1][j + 1] == 1) {
            count++;
        }
        if (j > 0 && board[i][j - 1] == 1) {
            count++;
        }
        if (j < board[0].size() - 1 && board[i][j + 1] == 1) {
            count++;
        }
        if (i < board.size() - 1 && j > 0 && board[i + 1][j - 1] == 1) {
            count++;
        }
        if (i < board.size() - 1 && board[i + 1][j] == 1) {
            count++;
        }
        if (i < board.size() - 1 && j < board[0].size() - 1 && board[i + 1][j + 1] == 1) {
            count++;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> matrix = board;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 0 && numberOfOnes(board, i, j) == 3) {
                    matrix[i][j] = 1;
                } else if (board[i][j] == 1 && numberOfOnes(board, i, j) < 2) {
                    matrix[i][j] = 0;
                } else if (board[i][j] == 1 && numberOfOnes(board, i, j) > 3) {
                    matrix[i][j] = 0;
                } else {
                    matrix[i][j] = board[i][j];
                }
            }
        }
        board = matrix;
    }
};