class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        for(int i = 0; i < path.size() ; i++){
            
            if(path[i] == '/'){
                ans.push_back(path[i]);
                string next = "";
                while(i + 1 < path.size() and path[i+1] != '/'){
                    next += path[++i];
                }
                //cout << "next = " << next << endl ;
                if(next == ".."){
                    ans.pop_back();
                    while(size(ans) > 0 and ans.back() != '/') ans.pop_back();
                    if(size(ans) > 0) ans.pop_back();
                }
                else if(next == "." or next == "") ans.pop_back();
                else{
                    ans += next;
                }
            }
        }
        if(size(ans) == 0) ans += "/";
        return ans;
    }
};