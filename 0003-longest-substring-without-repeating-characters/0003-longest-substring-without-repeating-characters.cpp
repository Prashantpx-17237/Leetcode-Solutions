class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int ans = 1, cur = 0;
       map<char, int> mp ;
        int n = s.length() ;
        int low = 0;
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(mp[s[i]])
            {
                while(low < i and mp[s[i]])
                    mp[s[low++]]--;
                mp[s[i]]++;
            }
            else
            {
                mp[s[i]]++;
            }
            cur = i - low + 1;
            ans = max(ans, cur);
        }
        ans = max(ans, cur);
        return ans;
    }
};