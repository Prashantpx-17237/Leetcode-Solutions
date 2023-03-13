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
    
    bool get(TreeNode* left, TreeNode* right)
    {
        if(left == NULL and right == NULL)
            return true;
        
        if(left and right and left -> val == right -> val)
            return (get(left -> right, right -> left) and get(left -> left, right -> right));
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return get(root -> left, root -> right);
    }
};