class Solution {
public:
    vector<vector<int>> dp;
    int sum(int i, int j, string& s1, string& s2){
        if(i >= s1.length() and j >= s2.length())
            return 0;
        
        int& ans = dp[i][j];
        if(ans != -1) return ans;
        
        if(i >= s1.length()){
            int cur= 0;
            while(j < s2.length()) cur += int(s2[j++]);
            return ans = cur;
        }
        
        if(j >= s2.length()){
            int cur= 0;
            while(i < s1.length()) cur += int(s1[i++]);
            return ans = cur;
        }
        
        if(s1[i] == s2[j]) return ans = sum(i+1, j+1, s1, s2);
        
        
        int ans1 = min((int)(s1[i]) + sum(i+1, j, s1, s2), (int)(s2[j]) + sum(i, j+1, s1, s2));
        int ans2= (int)(s1[i]) + (int)(s2[j]) + sum(i+1, j+1, s1, s2);
        
        return ans = min(ans1, ans2);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size()+1, vector<int>(s2.length()+1, -1));
        return sum(0, 0, s1, s2);
    }
};