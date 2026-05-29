//https://leetcode.com/problems/linked-list-cycle/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        set<ListNode*> elementset;
        while(cur != nullptr){
            if(elementset.find(cur) != elementset.end()){
               return true; 
            }
            elementset.insert(cur);
            cur = cur -> next;

        }
        return false;
    }
};