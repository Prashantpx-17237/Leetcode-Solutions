class Solution {
public:
    vector<vector<int>> cache;
    int get(string& word1, string& word2, int i, int j, int n, int m)
    {
        int& ans = cache[i][j];
        if(i == n)
            return ans = (m - j); // insertion
        if(j == m)
            return ans = (n - i); // deletion
        
        if(ans != -1)
            return ans;
        if(word1[i] == word2[j])
            return ans = get(word1, word2, i+1, j+1, n, m);
        
        int ans1 = get(word1, word2, i, j+1, n, m); // insert
        int ans2 = get(word1, word2, i+1, j+1, n, m); // replace
        int ans3 = get(word1, word2, i+1, j, n, m); // deleted
        
        ans = 1 + min({ans1, ans2, ans3});
        return ans;
    }
        
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        cache.resize(n1 + 1, vector<int>(n2 + 1, -1));
        return get(word1, word2, 0, 0, n1, n2);
    }
};