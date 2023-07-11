/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> ans;
    
    void addEdge(TreeNode* r1, TreeNode* r2, vector<vector<int>>& adj){
        adj[r1->val].push_back(r2->val);
        adj[r2->val].push_back(r1->val);
    }
    
    void getEdges(TreeNode* root, vector<vector<int>>& adj){
        if(root == NULL or (root -> left == NULL and root -> right == NULL)) return;
        
        if(root -> left) addEdge(root, root->left, adj); //edges.push_back({root -> val, root -> left -> val});
        if(root -> right) addEdge(root, root->right, adj); //edges.push_back({root -> val, root -> right -> val});
        
        getEdges(root -> left, adj);
        getEdges(root -> right, adj);
    }
    
    
    void dfs(int u, int par, int count, int k, vector<vector<int>>& adj){
        
        if(count == k) ans.push_back(u);
        
        for(auto v : adj[u]){
            if(v != par){
                dfs(v, u, count + 1, k, adj);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<vector<int>> adj(501);
        getEdges(root, adj);       
/* 
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
  */
        
        dfs(target->val, -1, 0, k, adj);      
        return ans;
    }
};