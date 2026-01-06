vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int>pos(n+1);
    for(int i=0; i<n; i++)
        pos[A[i]] = i;
    
    for(int i=0; i<n && B>0; i++){
        if(A[i] != n-i){
            int index = pos[n-i];
            swap(A[i],A[index]);
            swap(pos[A[i]], pos[A[index]]);
            B--;
        }
    }
    
    return A;
}