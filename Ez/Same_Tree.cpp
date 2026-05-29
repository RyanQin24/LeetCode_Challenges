//https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recurseTree(p,q);
    }
    bool recurseTree(TreeNode*curp, TreeNode* curq){
        if(curp == nullptr && curq == nullptr){
            return true;
        }if(curp == nullptr || curq == nullptr || curp->val != curq->val ){
            return false;
        }
        return recurseTree(curp->left, curq->left) && recurseTree(curp->right, curq->right);
    }
};