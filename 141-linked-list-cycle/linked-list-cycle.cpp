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
        unordered_map <ListNode*, int> nodeMap;
        ListNode* temp = head;

        while(temp != NULL){
            if(nodeMap.find(temp) != nodeMap.end())
                return true;

            nodeMap[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
};