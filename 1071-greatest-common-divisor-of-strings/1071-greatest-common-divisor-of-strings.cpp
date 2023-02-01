class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        int gcd = __gcd(m, n);
        string concat = str1.substr(0, gcd);
        
        string t1 = "", t2 = "";
        
        while(t1.size() < n)
            t1 += concat;
        while(t2.size() < m)
            t2 += concat;
        
        if(t1 == str1 and t2 == str2)
            return concat;
        return "";
    }
};