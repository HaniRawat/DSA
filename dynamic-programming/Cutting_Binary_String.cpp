// Algorithm Works As:
// 1) Making Possible substring left part as power of five .
// 2) Same Recursively check for all substrings at right part as power of five.
// 3) Function isPoweroffive is checking from left to right logic for converting string to decimal.  (To ignore leading zeroes in substring we travells from left to right).
// 4) Inside above function check for given decimal number is power of five or not .
// 5)At last gives our Answer.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isPoweroffive(string s){
          if (s.length() == 0) return false;
          if (s[0] == '0') return false;  

        long long decimal =0;
        int power=1;
       for( int i=0 ;i<s.size() ;i++){
           //to ignore leading zeroes we used this method
          decimal= 2*decimal+(s[i] -'0') ;
        }
          if (decimal == 0) return false;
        while(decimal >1 ){
            if( decimal%5!=0) return false;
            decimal /=5;
        }
        return true;
       
    }
        
    int cuts(string s){
        int n = s.size();
        if(n==0 || s[0]=='0') return -1;
        if(isPoweroffive(s)) return 1;
        int minCut =INT_MAX;
        for(int i=1 ;i<s.size() ;i++){
            string left = s.substr(0,i);
            string right = s.substr(i);
            if(isPoweroffive(left)) {
                int rightCut = cuts(right);
                if(rightCut!=-1){
                    minCut =min(minCut ,1+rightCut);
                }
            }
        }
        return minCut!=INT_MAX?minCut:-1;
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   
cout << "~" << "\n";
}


    return 0;
}

// } Driver Code Ends