#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    /* Time Complexity: O(m * n * 4^L), Space Complexity: O(L) */
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base case: If the index reaches the word length, all characters are matched
        if (index == word.length()) {
            return true;
        }
        
        // Check boundaries and whether the current character matches the required character
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Store the original character and mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '*';
        
        // Recursively search in all 4 adjacent directions (down, up, right, left)
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        // Backtrack: Restore the original character so other paths can use this cell
        board[i][j] = temp;
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Iterate through every cell in the grid to find a valid starting point
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Trigger DFS only if the first character matches
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    // board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << sol.exist(board, word) << endl;
	return 0;
}