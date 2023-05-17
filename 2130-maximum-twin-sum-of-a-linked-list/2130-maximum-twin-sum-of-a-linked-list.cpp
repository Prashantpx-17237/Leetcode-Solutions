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
    int pairSum(ListNode* head) {
        int len = 0, ans = 0;
        auto tmp = head;
        stack<int> st;
        while(tmp != NULL){
            len++;
            st.push(tmp->val);
            tmp = tmp -> next;
        }
        tmp = head;
        
        while(tmp != nullptr){
            ans = max(ans, tmp->val + st.top());
            st.pop();
            tmp = tmp -> next;
        }
        
        return ans;
    }
};