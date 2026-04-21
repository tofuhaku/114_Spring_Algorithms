#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(m + n), Space Complexity: O(1) */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 右上角開始
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            int current = matrix[row][col];
            
            if (current == target) {
                return true;
            } else if (current > target) {
                col--;
            } else {
                row++;
            }
        }
        
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    Solution sol;
    cout << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;
	return 0;
}