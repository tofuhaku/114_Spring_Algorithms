#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(n), Space Complexity: O(n) */
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // store {y_i - x_i, x_i}
        deque<pair<int, int>> dq;
        int maxValue = INT_MIN;
        
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            
            // TODO 1: Remove points from the front that are outside the distance window k
            while (!dq.empty() && (x - dq.front().second) > k) {
                dq.pop_front();
            }
            
            // TODO 2: If deque is not empty, the front element has the maximum (y_i - x_i)
            // Current equation value = (y_i - x_i) + (y_j + x_j)
            if (!dq.empty()) {
                maxValue = max(maxValue, dq.front().first + y + x);
            }
            
            // TODO 3: Maintain the strictly decreasing monotonic property of the deque
            // If the current (y - x) is greater than or equal to the back of the deque,
            // the back elements are useless because the current element is larger and will live longer.
            int currentDiff = y - x;
            while (!dq.empty() && dq.back().first <= currentDiff) {
                dq.pop_back();
            }
            
            // TODO 4: Push the current point into the back of the deque
            dq.push_back({currentDiff, x});
        }
        
        return maxValue;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,3},{2,0},{5,10},{6,-10}};
    int k = 1;
    cout << sol.findMaxValueOfEquation(points, k) << endl;
	return 0;
}