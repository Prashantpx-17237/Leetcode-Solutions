class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses], indegree(numCourses, 0);
        
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        queue<int> q;        
        for(int i = 0 ; i < numCourses; i++) if(indegree[i] == 0) q.push(i);
        int count = q.size();
        
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            for(auto u : adj[tp]){
                indegree[u]--;
                if(indegree[u] == 0) {
                    q.push(u);
                    count++;
                }
            }
        }
        return count == numCourses;
    }
};