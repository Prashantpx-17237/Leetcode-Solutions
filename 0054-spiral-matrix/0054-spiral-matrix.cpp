class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x1 = 0, x2 = matrix.size() - 1, y1 = 0, y2 = matrix[0].size()-1;
        
        vector<int> ans;
        
        while(x1 <= x2 and y1 <= y2){
           
            //first row
            for(int i = y1 ; i <= y2 ; i++)
                ans.push_back(matrix[x1][i]);
            
            // last column
            for(int i = x1 + 1 ; i <= x2 ; i++)
                ans.push_back(matrix[i][y2]);
            
            // last row
            for(int i = y2 - 1 ; i >= y1 && (x2 - x1) > 0 ; i--)
                ans.push_back(matrix[x2][i]);
            
            // first column
            for(int i = x2-1 ; i > x1 && (y2 - y1) > 0 ; i--)
                ans.push_back(matrix[i][y1]);
            
            x1++, y1++, x2--, y2--;
        }
        
        return ans;
    }
};