int Solution::coinchange2(vector<int> &A, int B) {
    int n=A.size();
    int mod=1000007;
    vector<int> prev(B+1,0);
    for(int i=1;i<=B;i++)  if(i%A[n-1]==0) prev[i]=1;
    prev[0]=1;
    for(int ind=n-2;ind>=0;ind--)
    {  
         vector<int> cur(B+1,0);
          cur[0]=1;
        for(int target=1;target<=B;target++)
        {
            int not_take=(prev[target])%mod;
            int take=0;
            if(target>=A[ind]) take=(cur[target-A[ind]])%mod;
                cur[target] =(take+not_take)%mod;
               
        }
        prev=cur;
    }
    return prev[B]%mod;
}