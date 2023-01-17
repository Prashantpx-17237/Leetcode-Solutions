class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int sum = 0, cur = 0;
        for(auto i : s)
            sum += (i - '0');

        int len = s.length();
        int ans = len;
        for(int i = 0 ; i <= len ; i++)
        {
            int rem = sum - cur;
            int curAns = cur;
            curAns += (len - i - rem);
            
            ans = min(ans, curAns);
            if(i == len)
                break;
            cur += (s[i] - '0');
        }
        return ans;
    }
};