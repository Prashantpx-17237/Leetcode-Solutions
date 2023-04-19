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
    
    pair<int,int> get(TreeNode* node, int& ans){
        if(node == NULL)
            return {0, 0};
        
        pair<int, int> leftAns, rightAns, ret;
        ret = rightAns = leftAns = {0, 0};
        leftAns = get(node -> left, ans);
        if(node -> left != NULL)
            ret.first = leftAns.second + 1;
        
        rightAns = get(node->right, ans);
        if(node -> right != NULL)
            ret.second = rightAns.first + 1;
        
        ans = max({ans, ret.first, ret.second});
        return ret;
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        get(root, ans);
        return max(0, ans);
    }
};