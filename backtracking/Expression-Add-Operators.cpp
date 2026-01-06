//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(string& s, int target, int ind, vector<string>&ans, string output, int val, int prev){
        if(ind == s.length()){
            if(val == target)
                ans.push_back(output);
                
            return;
        }
        
        string temp = "";
        int curr = 0;
        for(int i=ind; i<s.length(); i++){
            temp += s[i];
            curr = curr*10 + (s[i]-'0');
            
            if(ind == 0)
                solve(s,target,i+1,ans,temp,curr,curr);
            else{
                solve(s,target,i+1,ans,output+"+"+temp,val+curr,curr);
                solve(s,target,i+1,ans,output+"-"+temp,val-curr,-1*curr);
                solve(s,target,i+1,ans,output+"*"+temp,val-prev+prev*curr,prev*curr);
            }
            
             if(s[ind]=='0') break;
        }
    }
    vector<string> addOperators(string S, int target) {
        int n = S.length();
        vector<string>ans;
        string output;
        solve(S,target,0,ans,output,0,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends