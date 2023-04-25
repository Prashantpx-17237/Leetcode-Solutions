class SmallestInfiniteSet {
private:
    set<int> st;
public:
    SmallestInfiniteSet() {
        for(int i = 1 ; i < 1001 ; i++) st.insert(i);
    }
    
    int popSmallest() {
        if(st.empty()) return -1;
        int smallest = *st.begin();
        st.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        if(!st.count(num))
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */