//https://leetcode.com/problems/merge-two-sorted-lists/description/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = list1; 
        ListNode* retval = list1; 
        ListNode** header = &head;
        while(list2 != nullptr){
            if((*header) == nullptr ||(list2->val) < ((*header)->val)){
                ListNode* temp = list2;
                list2 = list2->next;
                temp->next = *header; 
                if(*header == retval){
                    retval = temp;
                }
                *header = temp;
            }else{
                header = &((*header)->next);
            }
        }
        return retval;
    }
};