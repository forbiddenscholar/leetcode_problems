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
    ListNode *detectCycle(ListNode *head) {

        // using the optimal approach now -- tortoise and hare algo
        ListNode* fast = head;
        ListNode* slow = head;

        // if cycle or not
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next; 

            if(fast == slow){
                // we have our cycle
                // put slow to start of LL
                slow = head;
                // now increment both fast and slow by one
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }

                return slow;
            }

        }

        // no cycle return null
        return NULL;
    }
};