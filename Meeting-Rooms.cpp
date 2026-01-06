int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), [](const auto &a, const auto &b){
        return a[0] < b[0];
    });
    
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto &interval : A){
        if(!pq.empty() && pq.top() <= interval[0])
            pq.pop();
        pq.push(interval[1]);
    }
    return pq.size();
}