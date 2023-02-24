class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        
        for(auto i : nums)
        {
            if(i & 1) i *= 2;
            
            st.insert(i);
        }
        
        int ans = *st.rbegin() - *st.begin();
        
        while(*st.rbegin() % 2 == 0)
        {
            int val = *st.rbegin();
            st.erase(val);
            st.insert(val / 2);
            ans = min(ans, *st.rbegin() - *st.begin());
        }
        return ans;
    }
};