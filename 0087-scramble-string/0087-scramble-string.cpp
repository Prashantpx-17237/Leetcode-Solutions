class Solution {
public:
    map<pair<string, string>, bool> dp;
    bool can(string& s, string& t){
       
       if(s == t) return true;
        
        if(dp.find({s,t}) != dp.end())
            return dp[{s, t}];
        bool& ans = dp[{s, t}];
        int n = s.length();
        
        for(int i = 0; i < n-1 ; i++){
            
            string x = s.substr(0, i+1);
            string y = s.substr(i+1);
            string left = t.substr(0, i+1);
            string right = t.substr(i+1);
            
            if((y+x) == t) return ans = true;
            
            if(can(x, left) and can(y, right)) return ans = true;
            int l = x.size(), r = y.size();
            left = t.substr(0, r), right = t.substr(r);
            if(can(y, left) and can(x, right)) return ans = true;
        }
        return ans = false;
    }
    
    bool isScramble(string s1, string s2) {
        return can(s1, s2);
    }
};