vector<int> Solution::solve(vector<vector<int> > &A) {
    int v = 0;
    
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){
            minHeap.push(A[i][j]);
        }
    }
    while(minHeap.size() != 0){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}