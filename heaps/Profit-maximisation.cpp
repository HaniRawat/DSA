int Solution::solve(vector<int> &A, int B) {
    int cost = 0;
    priority_queue<int>pq;
    
    for(int i=0; i<A.size(); i++){
        pq.push(A[i]);
    }
    
    while(B-- && !pq.empty()){
        int top = pq.top();
        cost += top;
        pq.pop();
        pq.push(top-1);
    }
    
    return cost;
}