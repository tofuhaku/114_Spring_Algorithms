#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    // Helper function to calculate the number of ways to decode a single character
    int ways1(char c) {
        // TODO 1: Implement single character decoding rules
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    }

    // Helper function to calculate the number of ways to decode two characters combined
    int ways2(char c1, char c2) {
        // TODO 2: Implement two-character decoding rules
        // Case 1: "**" -> return 15 (from 11-19 and 21-26)
        if (c1 == '*' && c2 == '*') return 15;
        
        // Case 2: "*X"
        if (c1 == '*') return c2 <= '6' ? 2 : 1;
        
        // Case 3: "X*"
        if (c2 == '*') {
            if (c1 == '1') return 9;
            if (c1 == '2') return 6;
            return 0;
        }
        
        // Case 4: "XY"
        int num = (c1 - '0') * 10 + (c2 - '0');
        return num >= 10 && num <= 26 ? 1 : 0;
    }

public:
    int numDecodings(string s) {
        long long mod = 1e9 + 7;
        
        // TODO 3: Initialize DP variables
        // 'prev2' represents dp[i-2], initially 1 for the empty string base case
        // 'prev1' represents dp[i-1], initially the number of ways to decode s[0]
        long long prev2 = 1;
        long long prev1 = ways1(s[0]);
        
        // TODO 4: Loop from the second character to the end of the string
        for (int i = 1; i < s.length(); ++i) {
            long long curr = 0;
            
            // Step 4.1: Calculate current ways by taking 1 step from i-1
            curr = (prev1 * ways1(s[i])) % mod;
            
            // Step 4.2: Add ways by taking 2 steps from i-2
            curr = (curr + prev2 * ways2(s[i-1], s[i])) % mod;
            
            // Step 4.3: Roll the DP variables forward for the next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        
        // At the end, 'prev1' holds the final answer for the entire string
        return prev1;
    }
};

int main() {
    Solution sol;
    string s = "2*";
    cout << sol.numDecodings(s) << endl;
	return 0;
}