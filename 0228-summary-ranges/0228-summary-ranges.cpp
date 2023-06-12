class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int l = nums[0], r = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                r = nums[i];
            }
            else{
                if(l == r) ans.push_back(to_string(l));
                else ans.push_back(to_string(l)+"->"+to_string(r));
                l = r = nums[i];
            }
        }
        if(l == r) ans.push_back(to_string(l));
        else ans.push_back(to_string(l)+"->"+to_string(r));
                
        return ans;
    }
};