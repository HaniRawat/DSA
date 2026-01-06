vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int>s={A,B,C};
    
    vector<int>ans(D);
    
    for(int i=0; i<D; i++){
        int j = *s.begin();
        s.erase(s.begin());
        
        s.insert(j*A), s.insert(j*B), s.insert(j*C);
        ans[i] = j;
    }
    return ans;
}