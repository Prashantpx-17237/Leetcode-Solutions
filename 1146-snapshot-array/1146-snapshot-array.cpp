class SnapshotArray {
public:
    int snapid = 0;
    map<pair<int, int>, int> data; // key, ind, val
    map<int, vector<int>> lastUpd;
    SnapshotArray(int length) {
        for(int i = 0 ; i < length; i++) {
            data[{snapid, i}]  = 0; 
            lastUpd[i].push_back(snapid);
        }
    }
    
    void set(int index, int val) {
        data[{snapid, index}] = val;
        
        if(lastUpd[index].back() != snapid)
            lastUpd[index].push_back(snapid);
    }
    
    int snap() {
        return snapid++;
    }
    
    int get(int index, int snap_id) {
        if(data.find({snap_id, index}) != data.end())
            return data[{snap_id, index}];
        int ind = get_snapid(snap_id, index);
        //cout << data[{ind, index}] << endl;
        return data[{ind, index}];
    }
    
    int get_snapid(int snap_id, int index){
        //cout << "called at " << snap_id << " index = " << index << endl ;
        int ind = lower_bound(lastUpd[index].begin(), lastUpd[index].end(), snap_id) - lastUpd[index].begin();
        //cout << ind << endl ;
        return lastUpd[index][ind-1];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */