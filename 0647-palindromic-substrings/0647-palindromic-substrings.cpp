class Solution {
public:
    int countSubstrings(string s) {
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
        int count = 0;
        
        for(auto i : cache)
            for(auto j : i)
                if(j)
                    count++;
        
        return count;
    }
};