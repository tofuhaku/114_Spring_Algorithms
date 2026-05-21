#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = (n - 1) / 2;
        int right = n - 1;
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                res.push_back(nums[left--]);
            } 
            else {
                res.push_back(nums[right--]);
            }
        }
        
        nums = res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,5,1,1,6,4};
    sol.wiggleSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
	return 0;
}