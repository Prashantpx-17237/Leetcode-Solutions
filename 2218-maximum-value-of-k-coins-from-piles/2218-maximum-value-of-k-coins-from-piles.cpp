class Solution {
public:
    
    int get(vector<vector<int>>& piles, int k, vector<vector<int>>& totVal, int level){
        if(level == piles.size() or k <= 0)
            return 0;
        
        int& ans = totVal[level][k];
        if(ans != -1) return ans;
        int val = 0;
        for(int j = 0 ; j <= min((int)piles[level].size(), k) ; j++){
            int i = j-1;
            //cout << level << "  " << j << endl;
            if(i >= 0)
                val = max(val, piles[level][i] + get(piles, k-j, totVal, level + 1));
            else
                val = max(val, get(piles, k-j, totVal, level + 1));
        }
        ans = val;
        return ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i = 0 ; i < piles.size() ; i++){
            for(int j = 1 ; j < piles[i].size(); j++){
                piles[i][j] += piles[i][j-1];
            }
        }
        
        vector<vector<int>> totVal(piles.size(), vector<int>(k+1, -1));
        return get(piles, k, totVal, 0);       
        
    }
};