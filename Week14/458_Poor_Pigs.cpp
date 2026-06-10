#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Calculate how many states one pig can represent
        int base = minutesToTest / minutesToDie + 1;
        int pigs = 0;
        int current_buckets = 1;
        
        // Keep adding pigs until the testable buckets cover the required amount
        while (current_buckets < buckets) {
            current_buckets *= base;
            pigs++;
        }
        
        return pigs;
    }
};

int main() {
    Solution sol;
    cout << sol.poorPigs(1000, 15, 60) << endl; // Example test case
	return 0;
}