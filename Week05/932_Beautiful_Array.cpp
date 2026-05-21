#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(n), Space Complexity: O(n) */
    unordered_map<int, vector<int>> memo;
    vector<int> beautifulArray(int n) {
        if (n == 1) {
            return {1};
        }
        
        // Return from cache if already computed
        if (memo.count(n)) {
            return memo[n];
        }
        
        vector<int> result;
        
        // TODO 1: Generate the odd part
        for (int x : beautifulArray((n + 1) / 2)) {
            result.push_back(2 * x - 1);
        }
        
        // TODO 2: Generate the even part
        for (int x : beautifulArray(n / 2)) {
            result.push_back(2 * x);
        }
        
        // Cache the result and return
        memo[n] = result;
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<int> result = sol.beautifulArray(n);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
	return 0;
}
