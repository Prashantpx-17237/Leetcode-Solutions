class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = size(pushed);
        int i = 0, j = 0;
        while(i < n){
            while(!st.empty() and st.top() == popped[j]){
                st.pop();
                j++;
            }
            if(popped[j] != pushed[i]) 
                st.push(pushed[i]);
            else
                j++;
            i++;
        }
        while(!st.empty() and st.top() == popped[j]){
                st.pop();
                j++;
            }
        cout << j << endl ;
        return j == n;
    }
};