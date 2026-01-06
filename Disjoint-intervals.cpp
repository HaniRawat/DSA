bool compareEndPoints(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), compareEndPoints);
    
    int count = 1;
    int lastEnd = A[0][1];
    
    for(int i = 1; i<A.size(); i++){
        if(A[i][0] > lastEnd){
            lastEnd = A[i][1];
            count++;
        }
    }
    return count;
}
