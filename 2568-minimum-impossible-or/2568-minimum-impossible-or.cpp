class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        vector<int> bit(31, 0);
        
        set<int> st;
        
        for(auto j : nums)
        {
            st.insert(j);
            long int mask = 1;
            for(int i = 0; i < 31 ; i++)
            {
                if((j & mask) == mask)
                {
                    bit[i]++;
                }
                mask *= 2;
            }
        }
        long long int mask = 1;
        for(int i = 0 ; i < 31 ; i++)
        {
            //cout << bit[i] << " ";
            if(bit[i] == 0 or !st.count(mask))
                return mask;

            mask *= 2;
        }
        //cout << endl;
        return mask;
    }
};