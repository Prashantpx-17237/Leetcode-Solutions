class Solution {
public:
    
    //vector<int> a, b;
    unordered_map <int, int> disa, disb;
    
    void dfs1(int node, int dis, vector<bool>& vis, vector<int>& edges)
    {
        vis[node] = true;
        disa[node] = dis;
        int nNode = edges[node];
        if(nNode == -1)
            return;
        if(vis[edges[node]])
            return;
        else
            dfs1(edges[node], dis+1, vis, edges);
    }
    void dfs2(int node, int dis, vector<bool>& vis, vector<int>& edges)
    {
        vis[node] = true;
        disb[node] = dis;
        int nNode = edges[node];
        if(nNode == -1)
            return;
        if(vis[edges[node]])
            return;
        else
            dfs2(edges[node], dis+1, vis, edges);
    }
    
    void mset(vector<bool>& vis)
    {
        for(int i = 0 ; i < vis.size(); i++)
            vis[i] = false;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<bool> vis;
        vis.resize(edges.size());
        mset(vis);     dfs1(node1, 0, vis, edges);
        
        mset(vis);     dfs2(node2, 0, vis, edges);
        
        int ans = -1;
        
        set<pair<int, int>> st;
        
        for(auto i: disa)
        {
            if(disb.count(i.first))
            {
                pair<int, int> tmp;
                tmp.first = max(i.second, disb[i.first]);
                tmp.second = i.first;
                st.insert(tmp);
            }
        }
        if(st.size() > 0)
            ans = (*st.begin()).second;
        return ans;
    }
};