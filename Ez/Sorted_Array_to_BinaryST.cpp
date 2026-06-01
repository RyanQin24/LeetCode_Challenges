//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* head = nullptr;
        int lowind = 0;
        int highind = nums.size() - 1;
        int mid = (lowind + highind)/2;
        head = new TreeNode();
        head->val = nums[mid];
        head->left = sortedArrayToSubBST(nums, lowind, (mid-1));
        head->right = sortedArrayToSubBST(nums, (mid+1), highind);
        return head;
    }

    TreeNode* sortedArrayToSubBST(vector<int>& nums, int minind, int maxind){
        if(minind > maxind){
            return nullptr;
        }
        int mid = (minind + maxind)/2;
        TreeNode* temp = new TreeNode();
        temp->val = nums[mid];
        temp->left = sortedArrayToSubBST(nums, minind, (mid-1));
        temp->right = sortedArrayToSubBST(nums, (mid+1), maxind);
        return temp;
    }
    
};