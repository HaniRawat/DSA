//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> coinsGame(int N, int K){
        vector<int>ans(K,0);
        ans[0] = N;
        
        for(int i=1; i<K; i++){
            if(i % 2 == 0){
                ans[0]--;
                ans[i]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
 {
	//code
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
        int N,K;
        cin>>N>>K;
        Solution obj;
        vector<int> ans;
        ans = obj.coinsGame(N, K);
        for(int i: ans)
            cout << i << " ";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends