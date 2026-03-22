#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int mergeSortAndCount(vector<int>& nums, vector<int>& temp, int left, int right) {
        // Base Case
        if (left >= right) {
            return 0;
        }
        
        int count = 0;
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(nums, temp, left, mid);
        count += mergeSortAndCount(nums, temp, mid + 1, right);
        
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2 * 1LL * nums[j]) {     // Beware of overflow
                j++;
            }
            
            count += j - (mid + 1);
        }
        
        // Merge
        int p1 = left;
        int p2 = mid + 1;
        int p_temp = left;
        
        while (p1 <= mid && p2 <= right) {
            if (nums[p1] <= nums[p2]) {
                temp[p_temp++] = nums[p1++];
            } else {
                temp[p_temp++] = nums[p2++];
            }
        }
        
        while (p1 <= mid) {
            temp[p_temp++] = nums[p1++];
        }
        
        while (p2 <= right) {
            temp[p_temp++] = nums[p2++];
        }
        
        // Copy back into the original array
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }        
        
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> temp(n);
        return mergeSortAndCount(nums, temp, 0, n - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,2,3,1};
    cout << sol.reversePairs(nums) << endl;
	return 0;
}