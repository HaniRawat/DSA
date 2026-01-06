//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      stack<char> st;
      string s1 = "pr",s2 = "rp";
      if(X < Y) {
          int temp = X;
          X = Y;
          Y = temp;
          
          string t = s1;
          s1 = s2;
          s2 = t;
      }
      long long ans = 0;
      int n = S.size();
      for(int i=n-1;i>=0;i--) {
          if(st.size() && st.top()==s1[1] && S[i]==s1[0]) {
              st.pop();
              ans+=X;
          }
          else st.push(S[i]);
      }
      string rem = "";
      while(!st.empty()) rem+=st.top(),st.pop();
      
      for(int i=rem.size()-1;i>=0;i--) {
          if(st.size() && st.top()==s2[1] && rem[i]==s2[0]) {
              st.pop();
              ans+=Y;
          }
          else st.push(rem[i]);
      }
      
      return ans;
      
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends