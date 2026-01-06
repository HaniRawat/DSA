int Solution::seats(string A) {
    long long n = A.length();
    int totalX = 0;
    int leftX = 0;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        if(A[i] == 'x')
            totalX++;
    }
    
    for(int i=0; i<n; i++){
        if(A[i] == 'x')
            leftX++;
        else
            ans = (ans + min(leftX, totalX-leftX))%10000003;
    }
    return ans;
}