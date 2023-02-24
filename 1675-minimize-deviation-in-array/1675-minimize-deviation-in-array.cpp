class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        
        int mn = nums[0] * 2;
        for(auto i : nums)
        {
            int toPush = i;
            if(i & 1)
                toPush *= 2;
            pq.push(toPush);
            mn = min(mn, toPush);
        }
        int ans = pq.top() - mn;
        
        while(pq.top() % 2 == 0)
        {
            int val = pq.top();
            pq.pop();
            val /= 2;
            mn = min(mn, val);
            pq.push(val);
            ans = min(ans, pq.top() - mn);
        }
        return ans;
    }
};