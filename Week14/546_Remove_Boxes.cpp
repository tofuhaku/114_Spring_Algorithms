#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // TODO 1: Declare a 3D memoization array
    int memo[100][100][100];

    int calculate(vector<int>& boxes, int l, int r, int k) {
        // TODO 2: Base case
        if (l > r) {
            return 0;
        }

        // TODO 3: Memoization check
        if (memo[l][r][k] != 0) {
            return memo[l][r][k];
        }

        // TODO 4: Optimization (Crucial for avoiding TLE)
        // Group consecutive boxes of the same color on the right side.
        int orig_r = r;
        int orig_k = k;
        
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }

        // TODO 5: Option 1 - Cash Out
        // eliminate boxes[r] and the 'k' attached boxes
        int res = (k + 1) * (k + 1) + calculate(boxes, l, r - 1, 0);

        // TODO 6: Option 2 - Merge / Invest
        // Scan through the remaining sequence from 'l' to 'r - 1'.
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                // If we find a box of the same color, we try to clear the obstacles between 'i' and 'r'.
                // try_merge = (clear the obstacles between i+1 and r-1) + (merge the left part [l, i] with k+1 boxes)
                int try_merge = calculate(boxes, l, i, k + 1) + calculate(boxes, i + 1, r - 1, 0);
                res = max(res, try_merge);
            }
        }

        // TODO 7: Save and Return
        memo[l][orig_r][orig_k] = res;
        return res;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        // TODO 8: Initialize the memoization table with 0
        memset(memo, 0, sizeof(memo));
        
        // TODO 9: Start the Top-Down DP
        int n = boxes.size();
        return calculate(boxes, 0, n - 1, 0);
    }
};

int main() {
    Solution sol;
    vector<int> boxes = {1,3,2,2,2,3,4,3,1};
    cout << sol.removeBoxes(boxes) << endl;
	return 0;
}