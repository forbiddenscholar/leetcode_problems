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
    ListNode* oddEvenList(ListNode* head) {
        // now doing this in O(1) space complexity by changing the links
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        // making links for the odd and even indices
        while(evenTail != NULL && evenTail->next != NULL){
            oddTail->next = oddTail->next->next;
            evenTail->next = evenTail->next->next;

            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }

        // now connect oddTail with evenHead;
        oddTail->next = evenHead;

        return head;
    }
};