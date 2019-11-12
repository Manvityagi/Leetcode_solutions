/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/////////////////////////////////FIRST///////////////////////////////////////
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return last;
    } 
    
    void reorderList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL) return;
     
        //find mid
        ListNode* slow = head, *fast = head, *preslow = NULL;
        while(fast != NULL && fast->next != NULL){
            preslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast == NULL) preslow->next = NULL;
        
        //from mid till last reverse & get new mid_rev_head
        ListNode* revhead = reverse(slow);
        
        
        //traverse orignal list & reversed mid alternatively
        ListNode* tempcurr = head, *tempnext = head->next;
        ListNode* revcurr = revhead, *revnext = revhead->next;
        
        while(revcurr != NULL){
            tempcurr->next = revcurr;
            revcurr->next = tempnext;
            
            tempcurr = tempnext;
            if(tempnext != NULL)
            tempnext = tempnext->next;
            
            revcurr = revnext;
            if(revnext != NULL)
            revnext = revnext->next;
        }
    }
};

///////////////////////////SECOND//////////////////////////////////////////////

public void reorderList(ListNode head) {
            if(head==null||head.next==null) return;
            
            //Find the middle of the list
            ListNode p1=head;
            ListNode p2=head;
            while(p2.next!=null&&p2.next.next!=null){ 
                p1=p1.next;
                p2=p2.next.next;
            }
            
            //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
            ListNode preMiddle=p1;
            ListNode preCurrent=p1.next;
            while(preCurrent.next!=null){
                ListNode current=preCurrent.next;
                preCurrent.next=current.next;
                current.next=preMiddle.next;
                preMiddle.next=current;
            }
            
            //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
            p1=head;
            p2=preMiddle.next;
            while(p1!=preMiddle){
                preMiddle.next=p2.next;
                p2.next=p1.next;
                p1.next=p2;
                p1=p2.next;
                p2=preMiddle.next;
            }
        }