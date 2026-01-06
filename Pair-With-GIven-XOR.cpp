int Solution::solve(vector<int> &A, int B) {
    map<int,int>mp;
    vector<vector<int>>result;
    
    int n = A.size();
    for(int i=0; i<n; i++){
        int number = A[i];
        int target = number^B;
        
        if(mp.find(target) != mp.end()){
            vector<int>temp = {A[i],target};
            result.push_back(temp);
        }
        mp[number] = i;
    }
    int ans = result.size();
    return ans;
}