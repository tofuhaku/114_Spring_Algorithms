#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int left_len;                       // Size of the valid left zone
    unordered_map<int, int> mapping;    // Mapping from blacklist elements
    
public:
    Solution(int n, vector<int>& blacklist) {
        // TODO: Calculate the size of the left zone
        left_len = n - blacklist.size();
        
        // TODO: Create a fast lookup table for the blacklist
        unordered_set<int> blacklist_set(blacklist.begin(), blacklist.end());
        
        // TODO: Build the mapping
        int last = n - 1;
        for (int b : blacklist) {
            if (b >= left_len) {
                continue;
            }
            while (blacklist_set.count(last)) {
                last--;
            }
            mapping[b] = last;
            last--;
        }
    }
    
    int pick() {
        // TODO: O(1) Random pick
        int r = rand() % left_len;
        if (mapping.count(r)) {
            return mapping[r];
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
int main() {
    // ["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
    // [[7, [2, 3, 5]], [], [], [], [], [], [], []]
    int n = 7;
    vector<int> blacklist = {2, 3, 5};
    Solution* obj = new Solution(n, blacklist);
    cout << obj->pick() << endl;
    cout << obj->pick() << endl;
    cout << obj->pick() << endl;
    cout << obj->pick() << endl;
    cout << obj->pick() << endl;
    cout << obj->pick() << endl;
    cout << obj->pick() << endl;
	return 0;
}