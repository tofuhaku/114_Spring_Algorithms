#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int prev = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int cur = nums[i];
            if (cur <= prev) {
                prev = cur;
            } else {
                long long slices = 1LL * (cur + prev - 1) / prev;
                count += slices - 1;        // operations = slices - 1
                prev = cur / slices;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,9,3};
    cout << sol.minimumReplacement(nums) << endl;
	return 0;
}