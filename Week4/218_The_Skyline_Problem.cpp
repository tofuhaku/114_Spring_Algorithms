#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(n log n), Space Complexity: O(n) */
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        vector<pair<int, int>> events;  // (x, height)

        // TODO 1: extract all event points
        for (const auto& b : buildings) {
            int left = b[0], right = b[1], height = b[2];
            // Building start
            events.push_back({left, -height});
            // Building end
            events.push_back({right, height});
        }

        // TODO 2: sort event points
        sort(events.begin(), events.end());

        // TODO 3: use multiset to maintain the current active building heights
        multiset<int> heights;
        heights.insert(0);      // ground height
        int prevMaxHeight = 0;

        // TODO 4: sweep line
        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                // left border
                heights.insert(-h);
            } else {
                // right border
                heights.erase(heights.find(h));
            }

            // max height
            int currentMaxHeight = *heights.rbegin();

            // only record when height changes
            if (currentMaxHeight != prevMaxHeight) {
                result.push_back({x, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    // buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> result = sol.getSkyline(buildings);
    for (const auto& r : result) {
        cout << "[" << r[0] << "," << r[1] << "] ";
    }
    cout << endl;
	return 0;
}
