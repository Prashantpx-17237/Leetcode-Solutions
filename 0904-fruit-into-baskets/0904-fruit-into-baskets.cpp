class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        
        unordered_map<int, int> ump;
        int ans = 0, cur = 0, j = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cur++;
            ump[fruits[i]]++;
            if(ump.size() > 2)
            {
                while(ump.size() > 2 and j < i)
                {
                    ump[fruits[j]]--;
                    if(ump[fruits[j]] == 0)
                        ump.erase(fruits[j]);
                    j++;
                    cur--;
                }
                
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};