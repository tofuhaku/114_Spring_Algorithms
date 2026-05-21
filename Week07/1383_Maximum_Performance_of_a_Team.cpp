#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // TODO 1: Create a combined data structure for engineers
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i) {
            engineers.emplace_back(speed[i], efficiency[i]);
        }
        
        // TODO 2: Sort the engineers
        sort(engineers.begin(), engineers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        // TODO 3: Initialize variables for tracking
        priority_queue<int, vector<int>, greater<int>> speed_heap;
        long long speed_sum = 0, max_perf = 0;
        
        // TODO 4: Iterate through the sorted engineers
        for (const auto& engineer : engineers) {
            int speed = engineer.first;
            int efficiency = engineer.second;
            
            // Step 4.1: Add the current speed to the heap and update 'speed_sum'
            speed_heap.push(speed);
            speed_sum += speed;
            
            // Step 4.2: Maintain the team size constraint (k)
            if (speed_heap.size() > k) {
                speed_sum -= speed_heap.top();
                speed_heap.pop();
            }
            
            // Step 4.3: Calculate current performance and update 'max_perf'
            max_perf = max(max_perf, speed_sum * efficiency);
        }
        
        // TODO 5: Return the result modulo 10^9 + 7
        int MOD = 1E9 + 7;
        return max_perf % MOD;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 2;
    cout << sol.maxPerformance(n, speed, efficiency, k) << endl;
	return 0;
}