class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        
        vector<int> lis(n, 1);
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = i - 1 ; j > -1; j--)
            {
                if(pairs[j][1] < pairs[i][0])
                    lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
        int ans = 1;
        for(auto i : lis)
            ans = max(ans, i);
        return ans;
    }
};