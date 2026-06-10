#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo[2001];
    const int INF = 1e9;

    int dfs(vector<int>& arr1, vector<int>& arr2, int i, int prev) {
        if (i == arr1.size()) {
            return 0;
        }

        if (memo[i].count(prev)) {
            return memo[i][prev];
        }

        int res = INF;

        // Choice 1 - Keep arr1[i] without swapping
        if (arr1[i] > prev) {
            res = min(res, dfs(arr1, arr2, i + 1, arr1[i]));
        }

        // Choice 2 - Swap arr1[i] with a valid element from arr2
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            res = min(res, 1 + dfs(arr1, arr2, i + 1, *it));
        }

        return memo[i][prev] = res;
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int ans = dfs(arr1, arr2, 0, -1);

        return ans >= INF ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 5, 3, 6, 7};
    vector<int> arr2 = {1, 3, 2, 4};
    cout << sol.makeArrayIncreasing(arr1, arr2) << endl;
	return 0;
}