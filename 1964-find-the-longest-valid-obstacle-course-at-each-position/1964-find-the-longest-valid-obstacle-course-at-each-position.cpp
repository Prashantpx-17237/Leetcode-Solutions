class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans, tmp;
        
        for(int i = 0 ; i < obstacles.size() ; i++){
            int ind = -1;
            if(tmp.empty() or obstacles[i] >= tmp.back()) tmp.push_back(obstacles[i]);
            else{
                ind = upper_bound(tmp.begin(), tmp.end(), obstacles[i]) - tmp.begin();
                tmp[ind] = obstacles[i];
            }
            ans.push_back((ind == -1 ? tmp.size() : ind+1));
        }
        return ans;
    }
};