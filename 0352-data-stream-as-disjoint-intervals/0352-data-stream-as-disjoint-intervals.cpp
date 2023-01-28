class SummaryRanges {
public:
    
    set<int> nums;
    
    SummaryRanges() {
        nums.clear();
    }


    void addNum(int value) {
       nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        int left = -1, right = -1;    
        for(auto i : nums)
        {
            if(right == -1 or i == right + 1)
            {
                if(right == -1)
                    left = i;
                right = i;
            }
            else
            {
                ans.push_back({left, right});
                left = right = i;
            }
        }
        ans.push_back({left, right});
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */