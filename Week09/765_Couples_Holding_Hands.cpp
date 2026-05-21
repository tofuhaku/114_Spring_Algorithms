#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[row[i]] = i;
        }

        int count = 0;
        for (int i = 0; i < n; i += 2) {
            int p1 = row[i];
            int p2 = row[i + 1];

            int partner = p1 ^ 1;
            if (p2 != partner) {
                int partner_pos = pos[partner];
                std::swap(row[i + 1], row[partner_pos]);
                pos[p2] = partner_pos;
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> row = {0, 2, 1, 3};
    cout << sol.minSwapsCouples(row) << endl;
	return 0;
}