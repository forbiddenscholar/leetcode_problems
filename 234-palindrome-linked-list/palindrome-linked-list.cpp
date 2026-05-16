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
    bool isPalindrome(ListNode* head) {
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
    }
};