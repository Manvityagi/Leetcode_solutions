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
    ListNode* partition(ListNode* head, int x) {
        // ListNode head1(0),head2(0);
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        
        // cout << head1->val << " " << endl;
        // ListNode* running1 = &head1,*running2 = &head2;
        ListNode* running1 = head1,*running2 = head2;
        
        while(head != NULL){
            
            // cout << head1->val << " " << head1->next << endl;
            
            if(head->val < x){
                running1->next = head;
                running1 = running1->next;
            }else{
                running2->next = head;
                running2 = running2->next;
            }
            
            head = head->next;
        }
                // cout << head1->val << " " << head1->next->val << endl;

        running2->next = NULL;
        // running1->next = head2.next;
        running1->next = head2->next;
        
                cout << head1->val << " " << head1->next->val;

        return head1->next;
    }
};