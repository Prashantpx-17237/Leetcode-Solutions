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
    unordered_map<int, int> ump;
    TreeNode* get(vector<int>& in, vector<int>& po, int l, int r)
    {
        if(l > r)
            return NULL;
        TreeNode* node = new TreeNode();
        if(l == r)
        {
            node -> val = in[l];
            return node;
        }
        int rootind = -1;
        for(int j = po.size() - 1; j > -1 ; j--)
        {
            if(ump[po[j]] >= l and ump[po[j]] <= r)
            {
                rootind = ump[po[j]];
                break;
            }
        }
        node -> val = in[rootind];
        node -> left = get(in, po, l, rootind - 1);
        node -> right = get(in, po, rootind + 1, r);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return NULL;
        int l = 0, r = inorder.size() - 1;
        for(int i = 0 ; i <= r ; i++)
            ump[inorder[i]] = i;
        return get(inorder, postorder, l, r);
        
    }
};