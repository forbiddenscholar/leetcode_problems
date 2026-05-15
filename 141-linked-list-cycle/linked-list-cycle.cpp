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
    bool hasCycle(ListNode *head) {
        // using the bruteforce approach using hashmaps
        // this method will be replaced by tortoise and hare method when the  
        // ll is large to save memory space

        // bruteforce method :
        /*
        unordered_map <ListNode*, int> nodeMap;
        ListNode* temp = head;

        while(temp != NULL){
            if(nodeMap.find(temp) != nodeMap.end())
                return true;

            nodeMap[temp] = 1;
            temp = temp->next;
        }

        return false;

        */

        // optimal solution (tortoise and hare)

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            // if at any instance fast and slow pointers meet, there's a loop
            if(slow == fast)
                return true;
        }

        return false;
    }
};