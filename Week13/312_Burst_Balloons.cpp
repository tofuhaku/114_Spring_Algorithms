#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // TODO 1: Create a new array 'A' of size n + 2
        vector<int> A(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            A[i + 1] = nums[i];
        }

        // TODO 2: Initialize a 2D DP table of size (n + 2) * (n + 2) with 0
        // dp[i][j]: the maximum coins obtained by bursting all balloons in (i, j)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // TODO 3: Implement the Interval DP nested loops
        for (int i = n; i >= 0; --i) {
            
            // 'j' must be at least i + 2 to leave room for at least one balloon inside (i, j)
            for (int j = i + 2; j < n + 2; ++j) {
                
                // TODO 4: Iterate through all possible choices of 'k'
                // 'k': the LAST balloon to be burst in (i, j)
                for (int k = i + 1; k < j; ++k) {
                    // TODO 5: Update dp[i][j] with the maximum score
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }

        // TODO 6: Return the final answer
        // The answer is the maximum coins for the open interval (0, n + 1), which encloses all original balloons.
        return dp[0][n + 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,1,5,8};
    cout << sol.maxCoins(nums) << endl;
	return 0;
}