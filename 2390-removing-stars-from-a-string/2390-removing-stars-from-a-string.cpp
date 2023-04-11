class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans = "";
        for(char i : s){
            if(i != '*')
                ans.push_back(i); 
            else
                ans.pop_back();
        }
        return ans;
    }
};