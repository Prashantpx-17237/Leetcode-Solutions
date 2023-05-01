class Solution {
public:
    double average(vector<int>& salary) {
        int mn = salary[0], mx = salary[0];
        int sum = 0, n = salary.size();
        for(int i = 0 ; i < n ; i++){
            mx = max(mx, salary[i]);
            mn = min(mn, salary[i]);
            sum += salary[i];
        }
        
        sum -= (mn + mx);
        
        double ans = (sum * 1.0) / (n - 2);
        
        return ans;
    }
};