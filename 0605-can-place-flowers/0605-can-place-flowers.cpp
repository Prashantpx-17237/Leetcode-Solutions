class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int ans = 0;
        for(int i = 0 ; i < sz ; i++)
        {
            if(flowerbed[i] == 1){
                i++;
                continue;
            }
            
            if(flowerbed[i] == 0)
            {
                if(i + 1 < sz and flowerbed[i+1] == 1) continue;
                else{
                   // cout << "i = " << i << endl ;
                    ans++;
                    i++;
                }
            }
        }
        return ans >= n;
    }
};