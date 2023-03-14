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
    
    void get(TreeNode* root, int cur, int& sum)
    {
        cur = cur * 10 + root -> val;
        if(root -> left == NULL and root -> right == NULL)
        {
            sum += cur;
            return;
        }
        if(root -> left)
            get(root -> left, cur, sum);
        if(root -> right)
            get(root -> right, cur, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        get(root, 0, sum);
        return sum;
    }
};