vector<int> Solution::solve(vector<int> &A) {
    map<int,priority_queue<int,vector<int>,greater<int>>>mp;
    for(int i=0;i<A.size();i++){
        auto it=mp.find(A[i]);
        if(it!=mp.end()){
            auto q=mp[A[i]];
            int index=q.top();
            mp[A[i]].pop();
            A[index]++;
            mp[A[index]].push(index);
        }
         mp[A[i]].push(i);
    }
    return A;
}