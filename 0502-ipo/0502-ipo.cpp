class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> q;
        for(int i = 0 ; i < n ; i++)
            q.push_back({capital[i], profits[i]});
        
        sort(q.begin(), q.end());
        
        priority_queue<int> pq;
        int i = 0, pro = w;
        while(k > 0)
        {
            while(i < n and q[i].first <= w)
            {
                //cout << "i = " << i << " capital = " << q[i].first ;//<< endl ;
                //cout << " w = " << w << endl ;
                pq.push(q[i].second);
                i++;
            }
            
            if(pq.size() == 0)
                break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};