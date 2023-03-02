class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cnt = 0;
        string res = "";
        
        for(int i = 0 ; i < n ; i++)
        {
            if(i == 0)
            {
                cnt++;
                continue;
            }
            else
            {
                if(chars[i] == chars[i-1])
                    cnt++;
                else
                {
                    res += chars[i-1];
                    if(cnt > 1) res += to_string(cnt);
                    cnt = 1;
                }
            }
        }
        if(cnt > 0)
        {
            res += chars[n-1];
            if(cnt > 1) res += to_string(cnt);
        }
        chars.clear();
        int sz = res.length();
        for(int i = 0 ; i < sz; i++)
        {
            chars.push_back(res[i]);
        }
        return sz;
    }
};