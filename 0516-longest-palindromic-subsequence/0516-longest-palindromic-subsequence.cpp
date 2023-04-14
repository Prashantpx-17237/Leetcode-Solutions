class Solution {
public:
    int get(string& s, int i, int j, vector<vector<int>>& longSeq){
        if(i == j) return 1;
        if(i > j) return 0;
        
        int& ans = longSeq[i][j];
        
        if(ans != -1)
            return ans;
        
        if(s[i] == s[j])
            return ans = 2 + get(s, i+1, j-1, longSeq);
        
        int val1 = get(s, i+1, j, longSeq);
        int val2 = get(s, i, j-1, longSeq);
        return ans = max(val1, val2);
    }
        
    int longestPalindromeSubseq(string s) {
        int n = size(s);
        vector<vector<int>> longSeq(n, vector<int>(n, -1));
        return get(s, 0, n-1, longSeq);
    }
};