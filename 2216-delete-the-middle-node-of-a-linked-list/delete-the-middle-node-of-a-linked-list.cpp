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
    ListNode* deleteMiddle(ListNode* head) {
        // use fast and slow pointers as we do in finding mid for tortoise and hare method
        // but this time give a head start to the fast pointer
        // by already moving in 2 steps ahead in the start

        // edge case when only one node present
        if(head == NULL || head->next == NULL){
            return NULL;
        }       
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};