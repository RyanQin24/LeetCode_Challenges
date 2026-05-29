// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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
    int minDepth(TreeNode* root) {
       return recurseminDepth(root);
    }
    int recurseminDepth(TreeNode* cur){
        if(cur == nullptr){
            return 0;
        }
        if(cur->left == nullptr && cur->right == nullptr){
            return 1;
        }
        int leftHeight = recurseminDepth(cur->left);
        int rightHeight = recurseminDepth(cur->right);
        if(cur->right == nullptr || (leftHeight < rightHeight && cur->left != nullptr)){
            return leftHeight + 1;
        }
        return rightHeight + 1;
    }
};