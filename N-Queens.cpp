    bool check(int row,int n, int col,vector<string>&initial){
    for(int i=0;i<n;++i){
        if(initial[i][col]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;++i){
        if(initial[row][i]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if((i+j)==(row+col)){
                if(initial[i][j]=='Q')return false;
            }
            else if((i-j)==(row-col)){
                if(initial[i][j]=='Q')return false;
            }
        }
    }
    return true;
}
void place(vector<vector<string>>&ans,int n,int col,vector<string>&initial){
    if(col==n){
        ans.push_back(initial);
        return;
    }
    for(int i=0;i<n;++i){
        if(check(i,n,col,initial)==true){
            initial[i][col]='Q';
            place(ans,n,col+1,initial);
            initial[i][col]='.';
        }
    }
    return;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string>initial;
    string a="";
    for(int i=0;i<A;++i)a+='.';
    for(int i=0;i<A;++i){
        initial.push_back(a);
    }
   
    vector<vector<string>>ans;
    place(ans,A,0,initial);
    return ans;

}