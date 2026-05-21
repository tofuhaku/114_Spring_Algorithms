#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int start = 0;
        int total_fuel = 0;
        for (int i = 0; i < n; ++i) {
            total_fuel += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }

        return total_fuel >= 0 ? start : -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
	return 0;
}