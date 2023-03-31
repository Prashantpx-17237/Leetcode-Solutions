class Solution {
public:
    map<pair<int, int>, int> cache;
    int get(int i, int covered, vector<int>& cost, vector<int>& days){
        if(i == days.size())
            return 0;
        
        if(cache.find({i, covered}) != cache.end())
            return cache[{i, covered}];
        
        if(covered >= days[i])
            return cache[{i, covered}] = get(i+1, covered, cost, days);
        
        int ans1 = cost[0] + get(i+1, days[i], cost, days);
        int ans2 = cost[1] + get(i+1, days[i] + 6, cost, days);
        int ans3 = cost[2] + get(i+1, days[i] + 29, cost, days);
        return cache[{i, covered}] = min({ans1, ans2, ans3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return get(0, 0, costs, days);
    }
};