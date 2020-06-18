/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode* dummyhead = new ListNode(0);
        
    
        ListNode* curr = head;
        ListNode* next = curr->next;
        dummyhead->next = curr;
        ListNode* prev = dummyhead;
        
        while(next)
        {
            bool flag = 0;
            while(curr && next && curr->val == next->val)
            {
                flag = 1;
                curr = next;
                next = next->next;
            }
            if(flag)
                prev->next = next;
            else
                prev = curr;
            curr = next;
            if(next)
            next = next->next;
        }
        
       return dummyhead->next;  
    }
};