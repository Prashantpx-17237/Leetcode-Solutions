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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL, *cur;
        cur = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for(int i = 0 ; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                pq.push({lists[i] -> val, lists[i]});
        }
        
        while(!pq.empty())
        {
            ListNode* tmp = pq.top().second;
            //cout << tmp -> val << endl ;
            pq.pop();
            if(tmp -> next != NULL)
                pq.push({tmp->next -> val, tmp->next});
            if(head == NULL)
            {
                head = tmp;
                cur = head;
            }
            else
            {
                cur -> next = tmp;
                cur = cur->next;
            }
        }
        return head;        
    }
};