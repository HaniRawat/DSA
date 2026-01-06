vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n=B.size();
    int m=B[0].size();
    if(A==0){
        return B;
    }
    vector<vector<int>> pre_dp=B;
     vector<vector<int>> dp=B;
    int dx[]={1,0,0,-1};
    int dy[]={0,1,-1,0};
    for(int l=0;l<A;l++){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           
  //////now for each time check for max one index around it
                for(int k=0;k<=3;k++){
                   int x=i+dx[k];
                   int y=j+dy[k];
                   if(x>=0 && y>=0 && x<n && y<m){
                       dp[i][j]=max(dp[i][j],pre_dp[x][y]);
                   }
                   
                }
               
            }
        }
        pre_dp=dp;
      }
      return pre_dp;
    }