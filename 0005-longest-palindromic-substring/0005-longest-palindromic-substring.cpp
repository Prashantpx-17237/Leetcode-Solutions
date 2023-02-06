class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> cache(n, vector<bool> (n, false));
        
        for(int i = 0 ; i < n ; i++)
        {
            cache[i][i] = true;
            int j = 1;
            
            while(i - j > -1 and i + j < n)
            {
                if(cache[i-j][i+j] == true or s[i-j] != s[i+j])
                    break;
                cache[i-j][i+j] = true;
                j++;
            }
            j = i+1;
            int k = i;
            while(k > -1 and j < n)
            {
                if(s[k] != s[j] or cache[k][j] == true)
                    break;
                cache[k][j] = true;
                k--, j++;
            }
        }
        pair<int, int> ans = {0, 0};
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if(cache[i][j])
                {
                    int len = ans.second - ans.first + 1;
                    if(len < j - i + 1)
                    {
                        ans = {i, j};
                    }
                }
            }
        }
        string str = s.substr(ans.first, ans.second - ans.first + 1);
        return str;
    }
};