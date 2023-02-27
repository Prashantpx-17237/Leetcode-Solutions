/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    bool allSame(vector<vector<int>>& grid, int x, int y, int len)
    {
        int cnt[2] = {0, 0};
        for(int i = 0 ; i < len ; i++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                cnt[grid[i+x][j+y]]++;
            }
        }
        if(cnt[0] != 0  and cnt[1] != 0)
            return false;
        return true;
    }
    
    Node* get(vector<vector<int>>& grid, int x, int y, int len)
    {
        if(allSame(grid, x, y, len))
            return new Node(grid[x][y], true);
        
        Node* root = new Node(grid[x][y], false);
        root -> topLeft = get(grid, x, y, len / 2);
        root -> topRight = get(grid, x, y+len/2, len / 2);
        root -> bottomLeft = get(grid, x + len / 2, y, len / 2);
        root -> bottomRight = get(grid, x + len / 2, y + len / 2, len / 2);
            return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return get(grid, 0, 0, grid.size());
    }
};