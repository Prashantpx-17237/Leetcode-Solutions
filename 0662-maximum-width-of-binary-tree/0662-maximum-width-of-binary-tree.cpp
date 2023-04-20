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
    int widthOfBinaryTree(TreeNode* root) {
        long long int ans = 0;
        
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0LL});
        
        while(!q.empty()){
            
            int sz = q.size();
            ans = max(ans*1ULL, q.back().second - q.front().second + 1);
            
            for(int i = 0 ; i < sz ; i++){
                auto pair = q.front();
                q.pop();
                TreeNode* node = pair.first;
                long long int pos = pair.second;
                
                if(node -> left != NULL) q.push({node->left, pos * 1ULL* 2 + 0LL});
                if(node -> right != NULL) q.push({node->right, pos * 2ULL + 1LL});
            }
        }
        return ans;
    }
};