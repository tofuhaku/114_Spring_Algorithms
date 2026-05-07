#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (target > 1) {
            if (maxDoubles == 0) {
                moves += target - 1;
                break;
            }

            if (target % 2) {
                target--;
                moves++;
            }
            else {
                target /= 2;
                maxDoubles--;
                moves++;
            }
        }

        return moves;
    }
};

int main() {
    Solution sol;
    int target = 19, maxDouble = 2;
    cout << sol.minMoves(target, maxDouble) << endl;
	return 0;
}