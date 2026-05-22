#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int max_seen = nums[0];
        int right = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < max_seen) {
                right = i;
            }
            max_seen = max(max_seen, nums[i]);
        }

        int min_seen = nums[n - 1];
        int left = 0;
        for (int i = n - 1; i > -1; --i) {
            if (nums[i] > min_seen) {
                left = i;
            }
            min_seen = min(min_seen, nums[i]);
        }

        return right - left + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,6,4,8,10,9,15};
    cout << sol.findUnsortedSubarray(nums) << endl;
	return 0;
}