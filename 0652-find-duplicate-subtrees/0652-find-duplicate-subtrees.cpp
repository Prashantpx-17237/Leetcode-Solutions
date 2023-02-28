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
    map<string, pair<TreeNode*, bool>> mp;
    string get(TreeNode* root)
    {
        
        string ans = "";
        if(root == NULL)
        {
            if(mp.find(ans) != mp.end())
                mp[ans] = {root, false};
            else
                mp[ans].second = true;
            
            return ans;
        }
        
        string left = get(root -> left);
        string right = get(root -> right);
        
        ans = to_string(root->val);
        ans = "$" + left + ans + right + "#";
        
        if(mp.find(ans) != mp.end())
            mp[ans].second = true;
        else
            mp[ans] = {root, false};
        //cout << ans << endl ;
        return ans;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // left + root + right
        get(root);
        
        vector<TreeNode*> ans;
        for(auto i : mp)
            if(i.second.second == true)
                ans.push_back(i.second.first);
        
        return ans;
    }
};