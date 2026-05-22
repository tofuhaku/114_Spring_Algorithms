#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        dp[stones[0]].insert(0);

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int nextJump = jump - 1; nextJump <= jump + 1; ++nextJump) {
                    if (nextJump > 0 && dp.find(stone + nextJump) != dp.end()) {
                        dp[stone + nextJump].insert(nextJump);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};

int main() {
    Solution sol;
    vector<int> stones = {0,1,3,5,6,8,12,17};
    cout << sol.canCross(stones) << endl;
	return 0;
}