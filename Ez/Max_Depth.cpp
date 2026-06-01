https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return recurseDepth(root);
    }
    int recurseDepth(TreeNode* tree){
        if(tree == nullptr){
            return 0;
        }
        int left_subtree = recurseDepth(tree->left);
        int right_subtree = recurseDepth(tree->right);
        int max = left_subtree;
        if(right_subtree > max){
            max = right_subtree;
        }
        return max + 1;
    }
};