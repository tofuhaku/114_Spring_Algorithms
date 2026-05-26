#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 0) return 0;

        // TODO 1: Initialize a 2D DP array
        // dp[i][j] represents the minimum number of turns to print the substring s[i..j].
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i > -1; --i) {
            // TODO 2: Base Case
            dp[i][i] = 1;

            // Inner loop: start 'j' from 'i + 1' to the end of the string
            for (int j = i + 1; j < n; ++j) {
                // TODO 3: The baseline strategy (Print s[i] separately)
                // We spend 1 turn to print s[i], plus the turns needed for the rest: s[i+1..j].
                dp[i][j] = 1 + dp[i+1][j];

                for (int k = i + 1; k <= j; ++k) {
                    // TODO 4: The greedy optimization (Match found!)
                    if (s[i] == s[k]) {
                        // The problem is divided into two parts: [i, k-1] and [k+1, j].
                        // Note: If k == j, [k+1, j] is out of bounds, so its cost should be 0.
                        int turns_right = (k + 1 <= j) ? dp[k+1][j] : 0;
                        int turns_left = dp[i][k-1];
                        
                        // Update dp[i][j] with the minimum value
                        dp[i][j] = min(dp[i][j], turns_left + turns_right);
                    }
                }
            }
        }

        // TODO 5: Return the final answer
        return dp[0][n-1];
    }
};

int main() {
    Solution sol;
    string s = "aaabbb";
    cout << sol.strangePrinter(s) << endl;
	return 0;
}