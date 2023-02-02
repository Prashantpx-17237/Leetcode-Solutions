
unordered_map<char, int> ump;

bool cmp(string &a , string &b){
      int n1 = a.size();
      int n2 = b.size();
      
      for(int i = 0; i < min(n1 , n2); i++)
      {
          if(ump[a[i]] != ump[b[i]])
              return ump[a[i]] < ump[b[i]];
      }
      return n1 < n2;
    }

class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        //unordered_map<char, int> ump;
        ump.clear();
        for(int i = 0 ; i < order.size() ; i++)
            ump[order[i]] = i;
        
        vector<string> nWords = words;
        sort(words.begin(), words.end(), cmp);
        //cout << cmp(words[1], words[0]) << endl ;
        return words == nWords;
    }
};