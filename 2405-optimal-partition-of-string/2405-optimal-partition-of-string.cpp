class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int ans = 1;
        for(auto i : s){
            if(st.count(i)){
                ans++;
                st.clear();
            }
            st.insert(i);
        }
        return ans;
    }
};