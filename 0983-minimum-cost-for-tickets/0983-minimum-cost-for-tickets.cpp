class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> has(days.begin(), days.end());
        vector<int> cache(366, 0);
        for(int i = 1 ; i < 366 ; i++){
            if(has.count(i)){
                cache[i] = min({costs[0] + cache[i-1],
                                costs[1] + cache[max(0, i-7)],
                                costs[2] + cache[max(0, i - 30)]});
            }
            else cache[i] = cache[i-1];
        }
        return cache[365];
    }
};