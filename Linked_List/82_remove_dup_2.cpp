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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pp = dummy, *p = head, *c = head->next;
        
        while(c != NULL){
            int flag = 0;
            
            while(c != NULL && p->val == c->val){
                c = c->next;
                flag = 1;
            }
            
            if(flag){
                pp->next = c;
                p = c;
                if(c)
                    c = c->next;
            }else{
                pp = p;
                p = c;
                c = c->next;
            }
        }
        
        return dummy->next;
    }
};
