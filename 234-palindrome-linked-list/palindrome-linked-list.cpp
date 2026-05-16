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
private:
    ListNode* findMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* revLL(ListNode* head){
        if(head->next == NULL)
            return head;
        ListNode* newHead = revLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        /*
        // trying the bruteforce approach using stack
        stack <int> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        // now check by popping each element of stack against the LL
        while(head != NULL){
            // if first and last element not same, return false
            if(st.top() != head->val)
                return false;
        
            head = head->next;
            st.pop();            
        }

        return true;
        */
        
        // the optimal approach :
        // 1. find middle using tortoise hare
        // 2. reverse the LL from the middle
        // 3. now check the head against new head from the reversed

        ListNode* mid = findMid(head);
        ListNode* newHead = revLL(mid);

        // now check the new LL
        // 1->2->3->4->5, 3 is mid, put a temp1 at 1 and temp2 at newhead3
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};