class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int to = min(n, m);
        int i = n - 1, j = m - 1;
        string ans = "";
        int carry = 0, ok = 0;
        while(to-- > 0)
        {
            int abit = a[i] - '0';
            int bbit = b[j] - '0';
            int sumbit = abit + bbit + (ok == 1 ? carry : 0);
            //cout << sumbit << endl ;
            if(sumbit >= 2)
            {
                carry = 1;
                ok = 1;
            }
            else
            {
                ok = 0;
                carry = 0;
            }
            sumbit %= 2;
            ans += ('0' + sumbit);
            i--, j--;
        }
        to = min(n, m);
        while(i > -1)
        {
            int abit = a[i] - '0';
            int sumbit = abit + (ok == 1 ? carry : 0);
            
            if(sumbit >= 2)
            {
                carry = 1;
                ok = 1;
            }
            else
            {
                ok = 0;
                carry = 0;
            }
            sumbit %= 2;
            ans += ('0' + sumbit);
            i--;
        }
        while(j > -1)
        {
            int bbit = b[j] - '0';
            int sumbit = bbit + (ok == 1 ? carry : 0);
            
            if(sumbit >= 2)
            {
                carry = 1;
                ok = 1;
            }
            else
            {
                ok = 0;
                carry = 0;
            }
            sumbit %= 2;
            ans += ('0' + sumbit);
            j--;
        }
        if(ok == 1)
            ans += "1";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};