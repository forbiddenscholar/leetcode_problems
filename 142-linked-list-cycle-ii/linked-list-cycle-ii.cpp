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
        // using the bruteforce apporach using unordered_set
        /*
        unordered_set <ListNode*> visited;
        // loop until we reach the end of ll (Null)
        while(head != NULL){
            // if current node is visited, we got the cycle's head
            if(visited.find(head) != visited.end())
                return head;
            
            // else visiting first time, so insert in the set
            visited.insert(head);
            head = head->next;
        }

        // if exits off the loop, there is no cycle
        return NULL;
        */
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