#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long miss = 1;       // first missing number
        int index = 0;
        while (miss <= n) {
            if (index < nums.size() && nums[index] <= miss) {
                miss += nums[index];
                index++;
            }
            else {
                miss *= 2;
                patches++;
            }
        }

        return patches;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3};
    int n = 6;
    cout << sol.minPatches(nums, n) << endl;
	return 0;
}