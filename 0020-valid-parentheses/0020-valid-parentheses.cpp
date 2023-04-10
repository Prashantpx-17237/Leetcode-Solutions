class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i : s){
            if(i == '(' or i == '{' or i == '[')
                st.push(i);
            else{
                if(st.empty() or (i == ')' and st.top() != '(') or (i == '}' and st.top() != '{') or (i == ']' and st.top() != '[')) return false;
                
                st.pop();
            }
        }
        return st.empty();
    }
};