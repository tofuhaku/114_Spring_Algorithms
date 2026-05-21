#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        // Node 0: head, Node n+1: tail
        vector<long long> val(n + 2);
        vector<int> prv(n + 2), nxt(n + 2);
        vector<bool> deleted(n + 2, false);

        // Link 0 <-> 1 <-> 2 <-> ... <-> n <-> n+1
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
            prv[i] = i - 1;
            nxt[i] = i + 1;
        }
        prv[0] = -1;        // head has no left neighbor
        nxt[0] = 1;         // head's right neighbor is node 1
        prv[n + 1] = n;     // tail's left neighbor is node n
        nxt[n + 1] = -1;    // tail has no right neighbor
        
        // min-heap by pair_sum
        using T = tuple<long long, int, int>;           // <pair_sum, left_index, right_index>
        priority_queue<T, vector<T>, greater<T>> heap;

        // Push all adjacent pairs into the heap
        for (int i = 1; i < n; ++i) {
            heap.push({val[i] + val[i + 1], i, i + 1});
        }

        // Count initial inversions
        int inversions = 0;
        for (int i = 1; i < n; ++i) {
            if (val[i] > val[i + 1]) {
                inversions++;
            }
        }
        
        int ops = 0;
        while (inversions > 0) {
            // Pop the pair with the smallest sum from the heap
            auto [psum, L, R] = heap.top();
            heap.pop();

            // Lazy deletion check: if either L or R is already deleted, or they are no longer adjacent, skip
            if (deleted[L] || deleted[R] || nxt[L] != R) {
                continue;
            }
            
            if (psum != val[L] + val[R]) {
                continue;
            }
            
            // Remove the contribution of the old pairs to inversions before merging
            // Consider three old pairs: (prv[L], L), (L, R), (R, nxt[R])
            if (prv[L] != 0 && val[prv[L]] > val[L]) {
                inversions--;
            }
            if (val[L] > val[R]) {
                inversions--;
            }
            if (nxt[R] != n + 1 && val[R] > val[nxt[R]]) {
                inversions--;
            }
            
            // Merge R into L
            if (nxt[R] != n + 1) {
                prv[nxt[R]] = L;
            }
            nxt[L] = nxt[R];
            val[L] = val[L] + val[R];
            deleted[R] = true;
            
            // Add the contribution of the new pairs
            if (prv[L] != 0 && val[prv[L]] > val[L]) {
                inversions++;
            }
            if (nxt[L] != n + 1 && val[L] > val[nxt[L]]) {
                inversions++;
            }
            
            // Push new adjacent pairs into the heap
            if (prv[L] != 0) {
                heap.push({val[prv[L]] + val[L], prv[L], L});
            }
            if (nxt[L] != n + 1) {
                heap.push({val[L] + val[nxt[L]], L, nxt[L]});
            }
            
            ops++;
        }

        return ops;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,2,3,1};
    cout << sol.minimumPairRemoval(nums) << endl;
    return 0;
}