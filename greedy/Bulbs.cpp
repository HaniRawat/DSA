int Solution::bulbs(vector<int> &A) {
    int ans=0;
    int n = A.size();
    
    for(int i=0; i<n; i++){
        if(ans%2 == 0 && A[i] == 0 ){
            ans++;
        }
        else if(ans%2 != 0 && A[i] == 1){
            ans++;
        }
    }
    return ans;
}