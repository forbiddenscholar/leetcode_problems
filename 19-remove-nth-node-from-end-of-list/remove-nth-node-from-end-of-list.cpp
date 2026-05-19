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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // using optimal approach, slow and fast pointers
        // 1. move the fast exactly n steps
        // 2. now move both fast and slow by 1 steps until fast reaches the end
        // 3. connect slow->next = slow->next->next

        // make a dummy node for edge cases
        ListNode* dummy_ptr = new ListNode(0, head);
        
        ListNode* fast = dummy_ptr;
        ListNode* slow = dummy_ptr;

        // moving fast exactly n steps
        while(n--)
            fast = fast->next;

        // now moving both fast and slow
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // now skip the node after slow
        slow->next = slow->next->next;

        // return the updated head
        return dummy_ptr->next;
    }
};