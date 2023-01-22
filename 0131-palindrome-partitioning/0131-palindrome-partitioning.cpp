class Solution {
public:
    
    bool check(string& s)
    {
        if(s.length() < 2)
            return s.length();
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    
    void get(string& s, int index, vector<vector<string>>& ans, vector<int>& cur)
    {
        int n = s.length();
        if(index == n)
        {
            vector<string> tmp;
            int f = 0;
            cur.push_back(n);
            for(int i = 0 ; i < cur.size() ; i++)
            {
                string str = "";
                for(int j = f ; j < cur[i]; j++)
                    str += s[j];
                f = cur[i];
                tmp.push_back(str);
                if(f == n)
                    break;
            }
            cur.pop_back();
            ans.push_back(tmp);
            return;
        }
        
        for(int i = index + 1; i <= n ; i++)
        {
            string sub = s.substr(index, i - index);
            //cout << sub  << "   " << check(sub) << endl ;
            if(check(sub))
            {
                cur.push_back(i);
                get(s, i, ans, cur);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<int> cur;
        get(s, 0, ans, cur);
        return ans;
    }
};