#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to hold the 4 boundary states for each segment
struct Node {
    long long f00, f01, f10, f11;
    Node() : f00(0), f01(0), f10(0), f11(0) {}
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    // Get the left child index
    int left(int node) { return node * 2; }

    // Get the right child index
    int right(int node) { return node * 2 + 1; }

    void build(int node, int start, int end, const vector<int>& nums) {
        // Handle the leaf node base case
        if (start == end) {
            tree[node].f00 = 0;
            tree[node].f01 = 0;
            tree[node].f10 = 0;
            tree[node].f11 = max(0LL, 1LL * nums[start]);
            return;
        }

        // Recursively build left and right subtrees, then pushUp
        int mid = start + (end - start) / 2;
        build(left(node), start, mid, nums);
        build(right(node), mid + 1, end, nums);
        pushUp(node);
    }

    void pushUp(int node) {
        // Merge the states from the left and right children
        Node leftChild = tree[left(node)];
        Node rightChild = tree[right(node)];
        tree[node].f00 = max(leftChild.f01 + rightChild.f00, leftChild.f00 + rightChild.f10);
        tree[node].f01 = max(leftChild.f01 + rightChild.f01, leftChild.f00 + rightChild.f11);
        tree[node].f10 = max(leftChild.f11 + rightChild.f00, leftChild.f10 + rightChild.f10);
        tree[node].f11 = max(leftChild.f10 + rightChild.f11, leftChild.f11 + rightChild.f01);
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        // Handle the leaf node update base case
        if (start == end) {
            tree[node].f00 = 0;
            tree[node].f01 = 0;
            tree[node].f10 = 0;
            tree[node].f11 = max(0LL, 1LL * val);
            return;
        }
        // Recursively update the correct subtree, then pushUp
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateTree(left(node), start, mid, idx, val);
        } else {
            updateTree(right(node), mid + 1, end, idx, val);
        }
        pushUp(node);
    }

public:
    SegmentTree(int size, const vector<int>& nums) {
        n = size;
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
    }

    void update(int idx, int val) {
        updateTree(1, 0, n - 1, idx, val);
    }

    long long queryMax() {
        return tree[1].f11;
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        long long total_sum = 0;

        SegmentTree segTree(nums.size(), nums);

        // Iterate through each query in queries
        // Update the segment tree with the new value
        // Add the current max sum to total_sum and apply modulo
        for (const auto& query : queries) {
            int idx = query[0];
            int val = query[1];
            segTree.update(idx, val);
            total_sum = (total_sum + segTree.queryMax()) % MOD;
        }

        return total_sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 9};
    vector<vector<int>> queries = {{1, -2}, {0, -3}};
    cout << sol.maximumSumSubsequence(nums, queries) << endl;
    return 0;
}