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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if(root == NULL)
            return ans ;
        
/* 
    We will do BFS and store values of each level in a vector tmp depending on a flag rev which is true when          we have to traverse from right to left and false otherwise. At the end we append this tmp in 2D vector ans   
*/
        
        queue<TreeNode*> q ;
        q.push(root) ;              // Start from root
        bool rev = false ;          // Initially we traverse from leftToRight, so rev = false  
        while(!q.empty())
        {
            int n = q.size() ;      // number of values on present level
            vector<int> tmp(n) ;
            for(int i = 0 ; i < n ; i++)
            {
                auto it = q.front() ;
                q.pop() ;
                
                int ind = (rev == false) ? i : n - i - 1 ;  // if rev = true then we have to fill tmp from                                                                       righToLeft otherwise from LeftToRight
                tmp[ind] = it -> val ;
                
                if(it -> left)                             // if left child of current node is not null
                    q.push(it->left) ;
                if(it -> right)                            // if right node of current child is not null
                    q.push(it -> right) ;
            }
            ans.push_back(tmp) ;           // push traversal of this level in ans
            rev ^= 1 ;                     // flips the value of rev
        }
        return ans ;
    }
};