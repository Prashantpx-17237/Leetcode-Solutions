class Solution {
public:
    string predictPartyVictory(string senate) {
        int countR = 0, countD = 0;
        queue<char> q;
        for(auto i : senate){
            countR += (i == 'R');
            countD += (i == 'D');
            q.push(i);
        }
        
        int cntR = 0, cntD = 0;
        while(countR > 0 and countD > 0){
            char cur = q.front(); q.pop();
            if(cur == 'R'){
                if(cntR > 0){
                    cntR--, countR--;
                }else{
                    cntD++;
                    q.push('R');
                }
            }
            else{
                if(cntD > 0){
                    cntD--, countD--;
                }else{
                    cntR++;
                    q.push('D');
                }
            }
        }
        
        return (countR > countD ? "Radiant" : "Dire");
    }
};