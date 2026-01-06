int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    map<int,int>mp;
    
    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        if(A[i]%2 != 0) //treat odd as 1 and even as 0 , then find the number of subarrays having sum = B
            sum+=1;
            
        ans += mp[sum-B];
        mp[sum]++;
    }
    return ans;
}