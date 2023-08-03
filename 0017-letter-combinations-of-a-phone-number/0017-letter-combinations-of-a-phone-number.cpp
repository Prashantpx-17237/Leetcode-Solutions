class Solution {
public:

    const vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void getAll(vector<string> &ans, string &digits, int u, string &cur)
    {
        if(u == digits.size())
        {
            ans.push_back(cur);
            return;
        }
        for(auto v : mp[digits[u] - '0'])
        {
            cur += v;
            getAll(ans, digits, u + 1, cur);
            cur.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        vector<string> ans;
        string cur = "";
        getAll(ans, digits, 0, cur);

        return ans;
    }
};