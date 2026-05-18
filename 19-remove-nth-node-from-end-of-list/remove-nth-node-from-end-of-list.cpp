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
        // find no. of node
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        // if there is only 1 node
        if(n == count)
            return head->next;
        // need to delete count-n+1 th node
        temp = head;
        for(int i = 0; i < count - n - 1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};