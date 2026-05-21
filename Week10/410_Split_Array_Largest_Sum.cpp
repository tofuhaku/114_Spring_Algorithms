#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;

            int boxes = 1;
            int capacity = 0;
            for (int num : nums) {
                capacity += num;
                if (capacity > mid) {
                    capacity = num;
                    boxes++;
                }
            }

            if (boxes <= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return right;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << sol.splitArray(nums, k) << endl;
	return 0;
}