class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char i : s){
            if(i != '*')
                st.push(i); 
            else
                st.pop();
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};