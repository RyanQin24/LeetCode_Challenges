//https://leetcode.com/problems/balanced-binary-tree/description/

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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return recurseBalanced(root, height);
    }
    bool recurseBalanced(TreeNode* cur, int &height){
        if(cur == nullptr){
            height = 0;
            return true;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        bool recurseLeft = recurseBalanced(cur->left, leftHeight);
        bool recurseRight = recurseBalanced(cur->right, rightHeight);
        if(leftHeight > rightHeight){
            height = leftHeight + 1;
        }else{
            height = rightHeight + 1;
        }
        return recurseLeft && recurseRight && ((leftHeight - rightHeight) < 2 && (leftHeight - rightHeight) > -2);
    }

    
};