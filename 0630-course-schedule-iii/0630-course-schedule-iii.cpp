class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int>& x, vector<int>& y){
            if(x[1] == y[1]) return x[0] < y[0];
            return x[1] < y[1];
        });
        
        // sort(courses.begin(), courses.end());
        priority_queue<int> pq;
        int ans = 0, curTime = 1; 
        for(int i = 0 ; i < courses.size(); i++){
            // can we include the course
            if(curTime + courses[i][0] - 1 <= courses[i][1]){
                ans++;
                pq.push(courses[i][0]);
                curTime += courses[i][0];
            }
            else if(!pq.empty() and pq.top() > courses[i][0]){
            // case when we cannot include extra course
            // but we can minize the time of doing same number of courses.
                int remove = pq.top();
                pq.pop();
                pq.push(courses[i][0]);
                curTime += (courses[i][0] - remove);
            }
        }
        return ans;
    }
};