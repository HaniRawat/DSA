int func(int ind , int a,vector<vector<int>>&dp,vector<vector<int> > &A){

    //base case

    if(ind==A.size()){

        return 0;

    }

    //memoization

    if(dp[ind][a]!=INT_MAX){

        return dp[ind][a];

    }

    //recursive case if we take colour a then we can take colour a+1 mod 3 and a+2 mod 3 in next indexed house

    dp[ind][a] = min({dp[ind][a],A[ind][a] + func(ind+1,(a+1)%3,dp,A) , A[ind][a] + func(ind+1,(a+2)%3,dp,A)});

    return dp[ind][a];

}


int Solution::solve(vector<vector<int> > &A) {

    int ans = 0;

    int n=A.size();

   

    //Here we will take colours as 0,1,2 and make a dp of [n+1][3]

    vector<vector<int>>dp(n+1,vector<int>(3,INT_MAX));

    //check for each start colour

    func(0,0,dp,A);

    func(0,1,dp,A);

    func(0,2,dp,A);

   

    ans= min({dp[0][0],dp[0][1],dp[0][2]});

    return ans;

}