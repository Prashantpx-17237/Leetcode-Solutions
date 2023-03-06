class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int got = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            got = arr[i] - i - 1;
            int prev = arr[i];
            int dif = 0;
            if(got >= k)
            {
                if(i == 0)
                    return (arr[i] > k ? k : k +1);
                for(int j = i - 1 ; j > -1 ; j--)
                {
                    dif = prev - arr[j] - 1;
                    if(got - dif < k)
                    {
                        return k + j + 1;
                    }
                    got -= dif;
                }
            }
        }
        return arr.size() + k;
    }
};