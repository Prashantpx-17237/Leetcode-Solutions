class LRUCache {
public:
    unordered_map<int, pair<int, int>> mp;
    int time, cap;
    // time, key
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    set<pair<int, int>> st;
    LRUCache(int capacity) {
        time = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        auto it = st.erase({mp[key].second, key});
        mp[key] = {mp[key].first, ++time};
        st.insert({mp[key].second, key});
        return mp[key].first;
    }
    
    void put(int key, int value) {
        int sz = st.size();
        if(mp.find(key) != mp.end()){
            auto it = st.erase({mp[key].second, key});
            mp[key] = {value, ++time};
            st.insert({mp[key].second, key});
        }
        else{
            if(sz == cap){
                pair<int, int> ele = *st.begin();
                st.erase(st.begin());
                mp.erase(ele.second);
            }
            mp[key] = {value, ++time};
            st.insert({time, key});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */