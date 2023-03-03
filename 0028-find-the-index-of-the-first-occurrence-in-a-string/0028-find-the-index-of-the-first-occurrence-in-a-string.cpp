class Solution {
public:
    
    bool check(string& tar, string& pat, int ind)
    {
        for(int i = 0 ; i < pat.length(); i++)
            if(pat[i] != tar[i+ind])
                return false;
        return true;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        
        if(n < m)
            return -1;
        int l = 0, hash = 0, cur = 0, mod = 100001;
        for(int i = 0 ; i < m ; i++)
        {
            hash += (needle[i] - 'a');
        }
        for(int i = 0 ; i < n; i++)
        {
            cur += (haystack[i] - 'a') ;
            if(i - l + 1 == m)
            {
                //cout << hash << " " << cur << endl ;
                if(hash == cur && check(haystack, needle, l))
                {
                    return l;
                }
                cur -= (haystack[l++] - 'a');
            }
        }
        return -1;
    }
};