class Solution {
public:
    
    long long cal(long long int n){
        return (n * (n + 1)) / 2;
    }
    
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0)
                count++;
            else
            {
                ans += cal(count);
                count = 0;
            }
        }
        ans += cal(count);
        return ans;
    }
};