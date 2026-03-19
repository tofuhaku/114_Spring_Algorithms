#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX;

            // BFS
            for (int n = q.size(); n--; ) {
                TreeNode* node = q.front();
                q.pop();

                // Check parity
                if (node->val % 2 == level % 2) {
                    return false;
                }
                
                // Check strict order
                if (level % 2) {
                    if (node->val >= prev_val) {
                        return false;
                    }
                }
                else {
                    if (node->val <= prev_val) {
                        return false;
                    }
                }
                
                prev_val = node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            level++;
        }

        return true;
    }
};

int main() {
    Solution sol;
    // root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->left = new TreeNode(2);
    cout << sol.isEvenOddTree(root) << endl;
	return 0;
}