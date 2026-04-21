#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* Time Complexity: O(n^2), Space Complexity: O(n) */
    string makeLargestSpecial(string s) {
        if (s.length() <= 2) {
            return s;
        }
        
        vector<string> subs;  // Store all top-level special substrings
        int count = 0;
        int start = 0;
        
        // TODO 1: Find all top-level special substrings
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                count++;
            } else {
                count--;
            }
            
            if (count == 0) {
                // Extract substring [start, i]
                string sub = s.substr(start, i - start + 1);
                
                // TODO 2: Recursively process the inner part
                // Remove outer '1' and '0', process middle, then wrap back
                string inner = sub.substr(1, sub.length() - 2);
                string processed = "1" + makeLargestSpecial(inner) + "0";
                
                subs.push_back(processed);
                start = i + 1;  // Move start to next substring
            }
        }
        
        // TODO 3: Sort all substrings in descending order (greedy)
        sort(subs.begin(), subs.end(), greater<string>());
        
        // TODO 4: Concatenate all substrings
        string result = "";
        for (const string& sub : subs) {
            result += sub;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "11011000";
    cout << sol.makeLargestSpecial(s) << endl;
	return 0;
}