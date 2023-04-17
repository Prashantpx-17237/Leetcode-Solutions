class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mxe = *max_element(begin(candies), end(candies));
        
        vector<bool> ans;
        for(int i : candies) ans.emplace_back(i+extraCandies >= mxe);
        return ans;
    }
};