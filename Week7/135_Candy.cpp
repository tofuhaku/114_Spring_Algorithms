#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // TODO 1: Initialize the candies array
        vector<int> candies(n, 1);
        
        // TODO 2: Left-to-Right Pass
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // TODO 3: Right-to-Left Pass
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // TODO 4: Calculate the total sum of candies
        int total_candies = 0;
        for (int candy : candies) {
            total_candies += candy;
        }
        
        // TODO 5: Return the total amount
        return total_candies;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1,2,2};
    cout << sol.candy(ratings) << endl;
	return 0;
}