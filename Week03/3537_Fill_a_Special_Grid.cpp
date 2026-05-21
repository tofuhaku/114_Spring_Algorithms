#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        // Base case: return a 1x1 grid
        if (n == 0) {
            return {{0}};
        }
        
        // Recursively fetch the grid for the n-1 state
        vector<vector<int>> prevGrid = specialGrid(n - 1);
        int prevSize = prevGrid.size();
        
        // Base offset for the current depth
        int offset = static_cast<int>(std::pow(4, n - 1));
        
        // New grid size
        int newSize = prevSize * 2;
        vector<vector<int>> newGrid(newSize, vector<int>(newSize, 0));
        
        for (int i = 0; i < prevSize; ++i) {
            for (int j = 0; j < prevSize; ++j) {
                int val = prevGrid[i][j];
                
                newGrid[i][j + prevSize] = val;                     // Top-Right
                newGrid[i + prevSize][j + prevSize] = val + offset; // Bottom-Right
                newGrid[i + prevSize][j] = val + 2 * offset;        // Bottom-Left
                newGrid[i][j] = val + 3 * offset;                   // Top-Left
            }
        }
        
        return newGrid; 
    }
};

int main() {
    Solution sol;
    vector<vector<int>> result = sol.specialGrid(2);
    
    // Print the result to verify
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}