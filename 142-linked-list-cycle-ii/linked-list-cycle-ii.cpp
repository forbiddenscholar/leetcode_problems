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
    }
};