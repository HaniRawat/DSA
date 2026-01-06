vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int>ans;
    deque<int>dq;
    int k = B;
    
    for(int i=0; i<A.size(); i++){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() && A[i] > A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        
        if(i >= k-1)
            ans.push_back(A[dq.front()]);
    }
    return ans;
}