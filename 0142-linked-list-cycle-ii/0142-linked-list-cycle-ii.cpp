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
        map<ListNode*, int> mp;
        int pos = 0;
        while(head != NULL)
        {
            if(mp.find(head) != mp.end())
                return head;
            mp[head] = pos++;
            head = head->next;
        }
        return NULL;
    }
};