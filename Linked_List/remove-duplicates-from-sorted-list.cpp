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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *prev = head;
        ListNode *next = prev->next;

        while (next)
        {
            while (next && prev->val == next->val)
            {
                next = next->next;
            }
            prev->next = next;
            prev = next;
            if (next)
                next = next->next;
        }

        return head;
    }
};