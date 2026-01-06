int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int>pq;
    
    for(int i=0; i<B.size(); i++){
        pq.push(B[i]);
    }
    
    long long int total = 0;
    
    while(A > 0 && !pq.empty()){
        total = (total + pq.top()) % 1000000007;
        if(pq.top()/2 > 0)
            pq.push(pq.top()/2);
            
        pq.pop();
        A--;
    }
    
    return total;
}