class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int ans = 0, r = INT_MIN;
        
        for(auto i : intervals){
            if(i[0] >= r){
                r = i[1];
            }
            else
                ans++;
        }
        return ans;
    }
};