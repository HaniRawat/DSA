int Solution::candy(vector<int> &A) {
    int ans = 1;
    
    int i = 1;
    
    while(i<A.size()){
        if(A[i] == A[i-1]){
            ans+=1;
            i++;
            continue;
        }
        int peak = 1;
        
        while(i< A.size() && A[i]>A[i-1])
        {
            peak++;
            ans+=peak;
            i++;
        }
            
        int down = 1;
        while(i<A.size() && A[i]<A[i-1])
        {
            ans+=down;
            down++;
            i++;
        }
        
        if(down>peak)
            ans+=(down-peak);
    }
    return ans;
}