// https://leetcode.com/problems/path-sum/description/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursePathSum(root, targetSum, 0);
    }
    bool recursePathSum(TreeNode* root, int targetSum, int currentSum){
        if(root == nullptr){
            return false;
        }
        if(root->left == nullptr && root->right == nullptr){
            return (currentSum + root->val) == targetSum;
        }
        int nexSum = currentSum + (root->val);
        return (recursePathSum(root->left,targetSum,nexSum) || recursePathSum(root->right,targetSum,nexSum));
    }
};