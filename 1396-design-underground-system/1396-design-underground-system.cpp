class UndergroundSystem {

private:
    map<int, pair<string, int>> curStation;
    map<pair<string, string>, vector<int>> timeBetStation;
public:
    UndergroundSystem() {
        curStation.clear();
        timeBetStation.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        curStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        timeBetStation[{curStation[id].first, stationName}].push_back(t - curStation[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = 0, cnt = 0;
        for(auto i : timeBetStation[{startStation, endStation}]){
            sum += i;
            cnt += 1;
        }
        return sum / cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */