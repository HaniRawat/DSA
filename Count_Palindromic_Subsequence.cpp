
//recursive
int mod = 1e9+7;
int recur(int i,int j,string &s){
    if(i > j) return 0;
    if(i == j) return 1;
    int num = recur(i+1,j,s)+recur(i,j-1,s);
    if(s[i] == s[j]) num++;
    else num -= recur(i+1,j-1,s);
    return num = num < 0 ? num+mod : num%mod;
}
long long int  countPS(string str){
    int n = str.size();
    return recur(0,n-1,str);
}

//memoization
int mod = 1e9+7;
int recur(int i,int j,vector <vector<int>> &dp,string &s){
    if(i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int num = recur(i+1,j,dp,s)+recur(i,j-1,dp,s);
    if(s[i] == s[j]) num++;
    else num -= recur(i+1,j-1,dp,s);
    return dp[i][j] = num < 0 ? num+mod : num%mod;
}
long long int  countPS(string str){
    int n = str.size();
    vector <vector<int>> dp(n,vector<int>(n,-1));
    return recur(0,n-1,dp,str);
}

//tabulation
long long int  countPS(string str){
    int n = str.size(),mod= 1e9+7;
    vector <vector<int>> dp(n,vector<int>(n));
    for(int i = 0;i < n;i++) dp[i][i] = 1;
    for(int i = n-2;i >= 0;i--){
        for(int j = i+1;j < n;j++){
            int num = dp[i+1][j]+dp[i][j-1];
            if(str[i] == str[j]) num++;
            else num -= dp[i+1][j-1];
            dp[i][j] = num < 0 ? num+mod : num%mod;
        }
    }
    return dp[0][n-1];
}

//space optimized
long long int  countPS(string str){
    int n = str.size(),mod= 1e9+7;
    vector <int> dp(n),t(n);
    dp[n-1] = 1;
    for(int i = n-2;i >= 0;i--){
        t[i] = 1;
        for(int j = i+1;j < n;j++){
            int num = dp[j]+t[j-1];
            if(str[i] == str[j]) num++;
            else num -= dp[j-1];
            t[j] = num < 0 ? num+mod : num%mod;
        }
        dp = t;
    }
    return dp[n-1];
}