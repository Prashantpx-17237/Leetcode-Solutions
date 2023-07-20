class Solution {
public:
    bool sameSign(int a, int b){
        return ((a <= 0 and b <= 0) or (a >= 0 and b >= 0));
    }
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        
        for(auto i : asteroids){
            if(ans.size() == 0 or sameSign(ans.back(), i) or ans.back() <= 0 and i >= 0) 
                ans.push_back(i);
            else{
                int cur = i; // negative
                while(ans.size() > 0){
                    int prev = ans.back(); // positive
                    ans.pop_back();
                    if((prev <= 0 and cur >= 0) or sameSign(prev, cur)){
                        ans.push_back(prev);
                        ans.push_back(cur);
                        cur = -2000;
                        break;
                    }
                    if(abs(cur) == prev){
                        cur = -2000;
                        break;
                    }
                    if(abs(cur) < prev){
                        cur = prev;
                    }
                   // cout << cur << endl ;
                }
                if(cur != -2000) ans.push_back(cur);
            }
        }
        return ans;
    }
};