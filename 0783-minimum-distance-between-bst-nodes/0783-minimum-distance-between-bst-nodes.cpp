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
    
    vector<int>  get(TreeNode* root)
    {
        vector<int> ans = {-1, root->val, root->val};
        if(root->left == NULL and root->right == NULL)
            return ans;
        
        vector<int> left, right;
        left = right = ans;
        
        if(root -> left != NULL)
        {
            left = get(root -> left);
            ans[1] = min(ans[1], left[1]);
            ans[2] = max(ans[2], left[2]);
            ans[0] = min({root->val - left[2], (left[0] == -1 ? root->val : left[0])});
        }
        if(root -> right != NULL)
        {
            right = get(root -> right);
            ans[1] = min(ans[1], right[1]);
            ans[2] = max(ans[2], right[2]);
            int val = (ans[0] == -1 ? right[1] : ans[0]);
            ans[0] = min({val, right[1] - root->val, (right[0] == -1 ? right[1] : right[0])});
        }
        return ans;
    }
    
    int minDiffInBST(TreeNode* root) {
        // minValTillNow, minOnLeft
        vector<int> ans = get(root);
        return ans[0];
    }
};