void solve(int index, int open, int close, vector<string>& ans, string curr, int n){
    if(index >= n*2){
        ans.push_back(curr);
        return;
    }
    
    if(open < n){
        curr += '(';
        solve(index+1, open+1, close,ans,curr,n);
        curr.pop_back();
    }
    
    if(close < open){
        curr += ')';
        solve(index+1, open, close+1, ans, curr, n);
        curr.pop_back();
    }
}


vector<string> Solution::generateParenthesis(int n) {
    int open = 0, close = 0, index = 0;
    vector<string>ans;
    string curr;
    
    solve(index, open, close, ans, curr, n);
    return ans;
}