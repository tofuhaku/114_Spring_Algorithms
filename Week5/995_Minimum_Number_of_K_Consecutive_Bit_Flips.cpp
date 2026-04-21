#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(n), Space Complexity: O(1) */
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int totalFlips = 0;
        int currentActiveFlips = 0;

        for (int i = 0; i < n; ++i) {
            // TODO 1: Remove the effect of the flip that has moved out of the sliding window
            // If the element at (i - k) was marked (> 1), its flip effect expires now
            if (i >= k && nums[i - k] > 1) {
                currentActiveFlips--;
                nums[i - k] -= 2;
            }

            // TODO 2: Determine if the current element needs to be flipped
            if ((nums[i] + currentActiveFlips) % 2 == 0) {

                // TODO 3: Check boundaries
                if (i + k > n) {
                    return -1;
                }

                // TODO 4: Execute the flip
                totalFlips++;
                currentActiveFlips++;

                // Mark the current index to indicate a flip started here
                nums[i] += 2;
            }
        }

        return totalFlips;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,1,0,1,1,0};
    int k = 3;
    cout << sol.minKBitFlips(nums, k) << endl;
    return 0;
}
