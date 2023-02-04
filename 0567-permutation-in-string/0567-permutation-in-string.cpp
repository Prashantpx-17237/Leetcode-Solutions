class Solution {
public:
    
    bool check(vector<int>& a, vector<int>& b)
    {
        for(int i = 0 ; i < 26 ; i++)
            if(a[i] != b[i])
                return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> toComp(26, 0), cur(26, 0);
        
        for(auto i : s1)
            toComp[i-'a']++;
        
        int k = s1.length(), j = 0;
        for(int i = 0 ; i < s2.length() ; i++)
        {
            cur[s2[i] - 'a']++;
            if(i - j + 1 == k)
            {
                if(check(toComp, cur))
                    return true;
                cur[s2[j]-'a']--;
                j++;
            }
        }
        return false;
    }
};