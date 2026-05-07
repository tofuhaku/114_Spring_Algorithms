#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        vector<bool> seen(26, false);
        int count = 1;
        for (char c : s) {
            if (seen[c - 'a']) {
                count++;
                seen.assign(26, false);
            }
            seen[c - 'a'] = true;
        }

        return count;
    }
};

int main() {
    Solution sol;
    string s = "ssssss";
    cout << sol.partitionString(s) << endl;
	return 0;
}