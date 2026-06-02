https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        int min;
        int max;
        return recurseValid(root,min,max);
    }
    bool recurseValid(TreeNode* root, int &min, int &max){
        if(root->left == nullptr && root->right == nullptr){
            min = root->val;
            max = root->val;
            return true;
        }
        int child_min = root->val;
        int child_max = root->val;
        min = root->val;
        max = root->val;
        bool valid = true;
        bool left_sub = root->left != nullptr; 
        bool right_sub = root->right != nullptr;
        if(left_sub){
            valid = valid && recurseValid(root->left,child_min,child_max) && child_max < root->val;
            if(child_min < min){
                min = child_min;
            }
            if(child_max > max){
                max = child_max;
            }
        }
        if(right_sub){
            valid = valid && recurseValid(root->right,child_min,child_max) && child_min > root->val;
            if(child_min < min){
                min = child_min;
            }
            if(child_max > max){
                max = child_max;
            }
        }
        return valid;
    }
};