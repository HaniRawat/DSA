void solve1(string A, int B, string& ans, int index){
    if(index == A.size() || B == 0){
        if(A > ans)
            ans = A;
        return;
    }
    
    for(int i = index; i<A.size(); i++){
        swap(A[index], A[i]);
        solve1(A,B-(i != index? 1 : 0),ans, index+1);
        swap(A[index], A[i]);
    }
}

string Solution::solve(string A, int B) {
    string ans = A;
    solve1(A,B,ans,0);
    return ans;
}