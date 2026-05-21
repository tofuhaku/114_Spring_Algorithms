#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int star_idx = -1;
        int match = 0;

        while (i < s.length()) {
            // Case 1: Exact match or '?' match.
            if (j < p.length() && (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            } 
            // Case 2: Encounter a '*'. Record the "save point".
            else if (j < p.length() && p[j] == '*') {
                star_idx = j;
                match = i;
                j++;
            } 
            // Case 3: Mismatch, but we have seen a '*' previously. Load the save point!
            else if (star_idx != -1) {
                // TODO: We must use the '*' to match one more character in 's'.
                match++;
                i = match;
                j = star_idx + 1;
            } 
            // Case 4: Mismatch and no '*' seen before. It's a dead end.
            else {
                return false;
            }
        }

        // TODO: There might be trailing '*' characters left in pattern 'p'.
        while (j < p.length() && p[j] == '*') {
            j++;
        }
        
        return j == p.length();
    }
};

int main() {
    Solution sol;
    string s = "cb", p = "?a";
    cout << sol.isMatch(s, p) << endl;
	return 0;
}