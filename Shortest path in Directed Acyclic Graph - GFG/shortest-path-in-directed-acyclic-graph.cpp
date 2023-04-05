//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> dis(N, -1);
        
        vector<vector<pair<int, int>>> adj(N); 
        
        for(auto i : edges){
            adj[i[0]].push_back({i[1], i[2]});
        }
        /*for(auto i : adj){
            for(auto j : i){
                cout << j.first << " " << j.second << " | ";
            }
            cout << endl ;
        }*/
        dis[0] = 0;
        
        queue<pair<int, int>> q; q.push({0, 0});
        
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            
            if(dis[p.first] != -1 and dis[p.first] < p.second) continue;
            
            //cout << p.first << "  currently in Qu " << p.second << endl ;
            
            for(auto i : adj[p.first]){
                int nextD = i.second + p.second;
                if(dis[i.first] == -1 or dis[i.first] > nextD){
                    dis[i.first] = nextD;
                    q.push({i.first, nextD});
                }
            }
        }
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends