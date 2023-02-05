class Solution {
public:
    bool check(vector<int>& a, vector<int>& b)
    {
        for(int i = 0 ; i < 26 ; i++)
            if(a[i] != b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> toComp(26, 0), cur(26, 0), ans;
        
        for(auto i : p)
            toComp[i-'a']++;
        
        int k = p.length(), j = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            cur[s[i] - 'a']++;
            if(i - j + 1 == k)
            {
                if(check(toComp, cur))
                    ans.push_back(j);
                cur[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};