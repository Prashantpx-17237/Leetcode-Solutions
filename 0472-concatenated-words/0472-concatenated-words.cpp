class Solution {
public:
    
    unordered_map<string, bool> mp;
    
    bool can (string s)
    {
        if(mp.find(s) != mp.end())
            return true;
        int n = s.length();
        string str = "";
        for(int i = 0 ; i < n ; i++)
        {
            str += s[i];
            if(mp.find(str) != mp.end())
            {
                string next = s.substr(i+1, n - i - 1);
                if(can(next))
                    return true;
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto i : words)
            mp[i] = true;
        vector<string> ans;
        for(auto i : words)
        {
            mp.erase(i);
            bool ok = can(i);
            if(ok)
                ans.push_back(i);
            mp[i] = true;
        }
        return ans;
    }
};