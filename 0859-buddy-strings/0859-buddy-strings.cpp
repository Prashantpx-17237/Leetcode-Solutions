class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int count = 0;
        vector<int> v(26, 0), v2(26, 0);
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != goal[i]) count++;
            v[s[i]-'a']++;
            v2[goal[i]-'a']++;
        }
        if(v != v2) return false;
        bool okay = false;
        for(auto i : v) okay  = okay | (i > 1);
        if(count == 2 or (count == 0 and okay)) return true;
        return false;
    }
};