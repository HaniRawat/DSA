vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int,set<int>>st;
    vector<int>ans;
    
    for(int i=0; i<A.size(); i++)
        st[A[i]].insert(1);
        
    for(int i=0; i<B.size(); i++)
        st[B[i]].insert(2);
        
    for(int i=0; i<C.size(); i++)
        st[C[i]].insert(3);
        
    for(auto i: st){
        if(i.second.size() > 1)
            ans.push_back(i.first);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
