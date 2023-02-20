class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        long int mask = 1;
        for(int i = 0 ; i < 31 ; i++)
        {
            bool ok = true;
            for(int j : nums)
                if(j == mask)
                    ok = false;
            if(ok)
                return mask;
            mask *= 2;
        }
        return mask;
    }
};