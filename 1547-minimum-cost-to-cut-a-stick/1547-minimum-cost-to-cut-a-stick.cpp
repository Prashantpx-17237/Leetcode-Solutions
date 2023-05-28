class Solution {
public:
    map<pair<int, int>, int> memo;
    int get(int i, int j, vector<int>& cuts){
        if(j - i == 1) return 0;
        if(memo.find({i, j}) != memo.end()) return memo[{i, j}];
        
        int k = upper_bound(cuts.begin(), cuts.end(), i)-cuts.begin();
        if(k == cuts.size() or cuts[k] >= j)
            return memo[{i, j}] = 0;
        long ans = j * 1LL*j;
        for(; k < cuts.size() and cuts[k] < j; k++){
            
            long left = get(i, cuts[k], cuts);
            long right = get(cuts[k], j, cuts);
            ans = min(ans, left + right  + (j-i)*1L);
        }
        return memo[{i, j}] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        
        sort(cuts.begin(), cuts.end());
        
        return get(0, n, cuts);
    }
};