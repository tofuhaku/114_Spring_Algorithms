#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SegmentTree {
private:
    vector<int> min_val;
    vector<int> max_val;
    vector<int> lazy;
    int n;

    // Helper function to get the left child index
    int left(int node) { 
        return node * 2; 
    }

    // Helper function to get the right child index
    int right(int node) { 
        return node * 2 + 1; 
    }

    // Update current node's min and max based on its children
    void pushUp(int node) {
        min_val[node] = min(min_val[left(node)], min_val[right(node)]);
        max_val[node] = max(max_val[left(node)], max_val[right(node)]);
    }

    // Propagate the lazy tag to children
    void pushDown(int node) {
        if (lazy[node] != 0) {
            int l_child = left(node);
            int r_child = right(node);
            int val = lazy[node];

            // Apply lazy value to left child
            lazy[l_child] += val;
            min_val[l_child] += val;
            max_val[l_child] += val;

            // Apply lazy value to right child
            lazy[r_child] += val;
            min_val[r_child] += val;
            max_val[r_child] += val;

            // Clear current node's lazy tag
            lazy[node] = 0;
        }
    }

    // Internal recursive method for range update
    void updateTree(int node, int start, int end, int l, int r, int val) {
        // If the current segment is completely within the update range
        if (l <= start && end <= r) {
            lazy[node] += val;
            min_val[node] += val;
            max_val[node] += val;
            return;
        }

        pushDown(node);
        int mid = start + (end - start) / 2;
        
        // Overlaps with left child
        if (l <= mid) {
            updateTree(left(node), start, mid, l, r, val);
        }
        // Overlaps with right child
        if (r > mid) {
            updateTree(right(node), mid + 1, end, l, r, val);
        }
        
        pushUp(node);
    }

    // Internal recursive method to find the smallest index with value 0
    int queryTree(int node, int start, int end, int l, int r) {
        // Out of bounds
        if (start > r || end < l) {
            return -1;
        }

        // If the current range cannot possibly contain a 0
        if (min_val[node] > 0 || max_val[node] < 0) {
            return -1;
        }

        // If it is a leaf node and its value is exactly 0
        if (start == end) {
            return (min_val[node] == 0) ? start : -1;
        }

        pushDown(node);
        int mid = start + (end - start) / 2;
        int res = -1;

        // Prioritize the left child to find the smallest index
        if (l <= mid) {
            res = queryTree(left(node), start, mid, l, r);
        }

        // If not found in the left child, try the right child
        if (res == -1 && r > mid) {
            res = queryTree(right(node), mid + 1, end, l, r);
        }

        return res;
    }

public:
    // Constructor initializes the tree arrays with 4 * n size
    SegmentTree(int size) {
        n = size;
        min_val.assign(4 * n + 1, 0);
        max_val.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }

    // Public API to add val to the range [l, r]
    void update(int l, int r, int val) {
        if (l <= r) {
            updateTree(1, 0, n - 1, l, r, val);
        }
    }

    // Public API to find the minimum index in range [l, r] where value is 0
    int query(int l, int r) {
        if (l <= r) {
            return queryTree(1, 0, n - 1, l, r);
        }
        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int max_len = 0;
        unordered_map<int, int> last_pos;
        
        // Initialize the segment tree
        SegmentTree st(n);
        
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            
            // Fix: Check if the number itself is even or odd
            int contribution = (x % 2 == 0) ? 1 : -1;
            
            // Find the last position of x (use 0 if it is the first appearance)
            int start_idx = last_pos.count(x) ? last_pos[x] + 1 : 0;
            
            // Add the contribution value to the segment tree in the range [start_idx, i]
            st.update(start_idx, i, contribution);
            
            // Query the segment tree for the smallest index l in [0, i] that has a value of 0
            int l = st.query(0, i);
            
            // If a valid index l is found, update max_len
            if (l != -1) {
                max_len = max(max_len, i - l + 1);
            }
            
            // Update the last_pos of x to the current index i
            last_pos[x] = i;
        }
        
        return max_len;
    }
};

int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {1, 2, 1, 2, 1, 3};
    cout << sol.longestBalanced(nums) << endl;
    return 0;
}