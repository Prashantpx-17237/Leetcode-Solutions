class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
                
        int n  = arr.size();
        int mod = 1E9 + 7;
        vector<int> left(n), right(n);
        stack<int> st;
        
        // minimum on left
        for(int i = 0 ; i < n ; i++)
        {
            if(st.empty())
            {
                left[i] = -1;
                st.push(i);
            }
            else
            {
                while(!st.empty() and arr[st.top()] >= arr[i])
                    st.pop();
                if(st.empty())
                    left[i] = -1;
                else
                    left[i] = st.top();
                st.push(i);
            }
        }
        
        while(!st.empty())
            st.pop();
        
        // minimum on right
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(st.empty())
            {
                right[i] = n;
                st.push(i);
            }
            else
            {
                while(!st.empty() and arr[st.top()] > arr[i])
                    st.pop();
                if(st.empty())
                    right[i] = n;
                else
                    right[i] = st.top();
                st.push(i);
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int noSub = (right[i] - i) * (i - left[i]);
            
            ans = ans +  (arr[i] % mod * 1LL * noSub % mod) % mod;
            ans %= mod;
        }
        return ans;
    }
};