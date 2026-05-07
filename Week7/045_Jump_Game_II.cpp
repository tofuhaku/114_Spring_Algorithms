#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // The array has only one element, no jumps needed
        if (nums.size() <= 1) {
            return 0;
        }

        // TODO 1: Initialize the three core variables
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // TODO 2: Iterate through the array
        // Important: You do not need to visit the last element (nums.size() - 1)
        // because if you reach it, you are already at the destination, 
        // and you shouldn't trigger another jump.
        for (int i = 0; i < nums.size() - 1; ++i) {
            // TODO 3: Continuously update the farthest index we can reach
            farthest = max(farthest, i + nums[i]);
            
            // TODO 4: Check if we have reached the limit of the current jump
            // If i == current_end:
            //   1. We must make another jump (increment jumps)
            //   2. Update current_end to the farthest index we found so far
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
            
            // Optimization (Optional): If current_end is already >= nums.size() - 1, 
            // we can break early to save execution time.
            if (current_end >= nums.size() - 1) {
                break;
            }
        }

        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout << sol.jump(nums) << endl;
	return 0;
}