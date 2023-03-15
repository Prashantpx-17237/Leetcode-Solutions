/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        
        q.push(root);
        int tot = 1;
        bool end = false;
        while(!q.empty())
        {
            int sz = q.size();
            if(sz < tot)
                end = true;
            
            int gotNull = 0;
            for(int i = 0 ; i < sz ; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur -> left == NULL and cur -> right != NULL)
                    return false;
                if(end == true  and (cur -> left or cur -> right))
                    return false;
                if(gotNull > 0 and (cur -> left or cur -> right))
                    return false;
                if(cur -> left != NULL)
                    q.push(cur -> left);
                else
                    gotNull++;
                if(cur -> right)
                    q.push(cur-> right);
                else
                    gotNull++;
            }
            tot = tot * 2;
        }
        return true;
    }
};