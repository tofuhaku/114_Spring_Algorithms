#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(n), Space Complexity: O(n) */
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int cur_flips = 0;
        int total_flips = 0;

        for (int i = 0; i < n; ++i) {
            cur_flips += diff[i];

            if ((nums[i] + cur_flips) % 2 == 0) {
                if (i + k > n) {
                    return -1;
                }

                total_flips++;
                cur_flips++;
                diff[i + k]--;
            }
        }
        
        return total_flips;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,1,0,1,1,0};
    int k = 3;
    cout << sol.minKBitFlips(nums, k) << endl;
    return 0;
}
