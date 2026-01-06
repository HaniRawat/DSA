//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        
        // In order to calculate the number of subsequences of type a^i, b^j, c^k we need to calculate
        // subsequences of type a^i, b^j and a^i
        
        // if we get a character "a" in the string, then the number of subsequences of type a^i will become
        // 2*(old_count) + 1, because there are 2 possibilities of either adding the new "a" or not adding
        // the new "a" in the old count , and one additional subsequence as the new "a" can start its own 
        // subsequence
        
        // if we get a character "b" in the string, then the number of subsequences of type a^i, b^j will become
        // 2*(old_count) + a, because 2 possibilities of adding and not adding new "b" in the end of the 
        // old subsequence and adding new "b" to all the subsequences of type a^i
        
        // similarly for the char "c", the count will be 2*old_count + ab
        
        int mod = 1e9+7;
        int a=0, ab=0, abc=0;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == 'a')
                a = ((2*a)% mod + 1)% mod;
                
            else if(s[i] == 'b')
                ab = ((2*ab)% mod + a)% mod;
                
            else
                abc = ((2*abc)% mod + ab)% mod;
        }
        
        return abc;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends