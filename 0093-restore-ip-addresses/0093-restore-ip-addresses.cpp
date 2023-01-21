class Solution {
public:
    
    bool check(string s)
    {
        if(s.length() > 3 or s.length() == 0)
            return false;
        if(stoi(s) > 255)
             return false;
        if(s.length() > 1 and s[0] == '0')
            return false;
        return true;
    }
    
    void backtrack(string &s, int index, int count, vector<string>& ans, string cur)
    {
        int n = s.length();
        if(index == n)
            return;
        if(count == 3)
        {
            string val = s.substr(index, n - index);
            if(check(val))
            {
                cur += val;
                ans.push_back(cur);
                return;
            }
            return;
        }
        
        string val = "";
        for(int i = 0 ; i < 3 ; i++)
        {
            if(i + index == n)
                break;
            val += s[index+i];
            if(check(val))
                backtrack(s, index + i + 1, count + 1, ans, cur + val + '.');
        }
        return ;        
    }
    
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12)
            return {};
        vector<string> ans;
        backtrack(s, 0, 0, ans, "");
        return ans;
    }
};