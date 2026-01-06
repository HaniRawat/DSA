//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0; i<N; i++){
            pq.push(A[i]);
        }
        long long top1, top2;
        for (int i = 0; i < K1; i++) {
            top1 = pq.top();
            pq.pop();
        }
        
        for (int i = 0; i < K2 - K1; i++) {
            top2 = pq.top();
            pq.pop();
        }
        // cout<<top1<<" "<<top2;
        long long sum = 0;
        
        for(int i=0; i<N; i++){
            if(A[i] > top1 && A[i] < top2)
                sum += A[i];
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends