int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    
    if(n == 3){
        return A[0]*A[1]*A[2];
    }
    
    sort(A.rbegin(),A.rend());
    int max1=A[0];
    int max2=A[1];
    int max3=A[2];
   
   
    int mini1=A[n-1];
    int mini2=A[n-2];
   
    int case1=0,case2=0;
    case1=max1*max2*max3;
   
    if(mini1<0 and mini2<0)
    case2=max1*mini1*mini2;
   
    return max(case1,case2);
}