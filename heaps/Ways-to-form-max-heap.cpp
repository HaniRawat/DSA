// Intuition => u have num no of nodes

// complete binary tree is tree where except for last level , all will be completely filled
// with 2 childrens

// T(n) = now take the max one element at top , no of left elements is (n-1) ,

// Now we have to take L elements to left , rest at right

// n-1 C L , take any of L elements from n-1 elements

// T(n) choose_L * T(L) * T(R)
#define ll long long
long long mod=1e9+7;

vector<vector<ll int>> nCrdp(102 , vector<ll int>(102 , -1));

int binomial( int n , int r)
{
    if(n==r || r==0)
    {
        return 1;
    }
   
    if(r==1)
    {
        return n;
    }
   
    if(nCrdp[n][r]!=-1)
    {
        return nCrdp[n][r];
    }
   
    int ans1 = binomial( n-1 , r-1);
    int ans2=binomial( n-1 , r);
   
    return nCrdp[n][r]=(ans1%mod + ans2%mod)%mod;
}


int find_left(int n)
{
    int h=log2(n);
    int v1=(1<<(h-1))%mod;
   
    int v2=(1<<(h))%mod;
   
    int val=  v1-1 + min(n-v2+1 , v1);
   
    return val%mod;
}
int func(vector<ll int> &dp , int num )
{
    if(num<=1)
    {
        return 1;
    }
   
    if(dp[num]!=-1)
    {
        return dp[num]%mod;
    }
   
   
    int L = find_left(num);
    int R=num-L-1;
   
     int choose_L=binomial( num-1 , L)%mod;
   
    int val1=func(dp ,L )%mod;
    int val2=func(dp , R )%mod;
   
    int ans=(choose_L%mod * (val1%mod * val2%mod)%mod)%mod;
   
    return dp[num]=ans%mod;
}


int Solution::solve(int num) {
    vector<ll int> dp(101 , -1);
    return  func(dp , num );
}