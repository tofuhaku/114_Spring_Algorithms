#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
                
        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    int target = 4;
    cout << sol.combinationSum4(nums, target) << endl;
	return 0;
}