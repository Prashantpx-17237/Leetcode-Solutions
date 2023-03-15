//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int get(string& s, int n, int i)
    {
        int l = 0, r = s.length() - 1;
        int j = i + n - 1;
        int ans = 0;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                if((l <= j and l >= i) and (r >= l and  r <= j))
                    return -1;
                ans++;
            }
            l++, r--;
        }
        return ans;
    }
    
    int specialPalindrome(string s1, string s2){
        int n = s1.length(), m = s2.length();
        if(n < m)
            return -1;
        int ans = -1;
        for(int i = 0 ; i + m < n + 1 ; i++)
        {
            string s = s1.substr(0, i) + s2 + s1.substr(i + m);
            int cnt = 0;
            for(int j = 0 ; j < m ; j++)
                if(s2[j] != s1[i+j])
                    cnt++;
                    
            int val = get(s, m, i);
            //cout << s << "  " <<  val << endl ;
            if(val != -1)
            {
                val += cnt;
                ans = (ans == -1 ? val : min(ans, val));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends