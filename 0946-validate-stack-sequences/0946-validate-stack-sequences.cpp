class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = size(pushed);
        int i = 0, j = 0;
        while(i < n){
            st.push(pushed[i]);
            while(!st.empty() and st.top() == popped[j]){
                st.pop();
                j++;
            }
            i++;
        }
        return j == n;
    }
};