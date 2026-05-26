#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int f = 0;
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int max_f = f;
        for (int i = 1; i < n; i++) {
            f = f + sum - n * nums[n - i];
            max_f = max(max_f, f);
        }
        return max_f;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 6};
    cout << sol.maxRotateFunction(nums) << endl;
	return 0;
}