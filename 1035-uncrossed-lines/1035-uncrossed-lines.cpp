class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> lines(n+1, vector<int>(m+1, 0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(nums1[i] == nums2[j]){
                    lines[i+1][j+1] = 1 + lines[i][j];
                }
                else{
                    lines[i+1][j+1] = max(lines[i][j+1], lines[i+1][j]);
                }
            }
        }
        return lines[n][m];
    }
};