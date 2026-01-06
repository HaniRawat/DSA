void solve(int i ,vector<vector<int>>& ans ,vector<int>& arr){
    if(i == arr.size()){
        ans.push_back(arr);
        return;
    }
    
    for(int j=i; j<arr.size(); j++){
        swap(arr[i], arr[j]);
        solve(i+1, ans, arr);
        swap(arr[i],arr[j]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int index = 0;
    vector<vector<int>>ans;
    solve(index,ans,A);
    return ans;
}