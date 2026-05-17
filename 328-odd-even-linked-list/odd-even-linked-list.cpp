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
        if(head == NULL || head->next == NULL)
            return head;

        vector <int> arr;
        ListNode* temp = head;
        // push all the odd indices in the array
        while(temp != NULL){
            arr.push_back(temp->val);
            if(temp->next == NULL)
                temp = NULL;
            else
                temp = temp->next->next;
        }
        // push all the even indices in the array
        temp = head->next;
        while(temp != NULL && temp->next != NULL){
            arr.push_back(temp->val);
            if(temp->next == NULL)
                temp = NULL;
            else
                temp = temp->next->next;
        }
        // now replace the values in the LL
        temp = head; 
        for (auto it : arr){
            temp->val = it;
            temp = temp->next;
        }

        return head;
    }
};