class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') ;
    }
    int maxVowels(string s, int k) {
        int ans = 0, cur = 0 ;
        for(int i = 0 ; i < s.length() && i < k ; i++)
        {
            if(isVowel(s[i]))
                cur++ ;
            ans = max(cur, ans) ;
        }
        for(int i = k ; i < s.length() ; i++)
        {
            if(isVowel(s[i]))
                cur++ ;
            if(isVowel(s[i-k]))
                cur-- ;
            ans = max(cur, ans) ;
        }
        return ans ;
    }
};