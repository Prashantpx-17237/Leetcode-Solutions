class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        int n = ideas.size();
       
        vector<unordered_set<string>> hash(26);
        
        // what we need is count of other newS which do not have same start as orginals 
        // of these newS 
        
        for(auto i : ideas)
        {
            string cur = i.substr(1);
            hash[i[0]-'a'].insert(cur);
        }
        
        // hash has all string starting with that char
        long long ans = 0;
        
        for(int i = 0 ; i < 26 ; i++)
        {
            for(int j = i + 1 ; j < 26; j++)
            {
                long c1 = 0, c2 = 0;
                for(auto str: hash[i])
                    if(!hash[j].count(str))
                        c1++;
                for(auto str : hash[j])
                    if(!hash[i].count(str))
                        c2++;
                
                ans += (c1 * c2);
            }
        }
   
        return ans * 2LL;
    }
};