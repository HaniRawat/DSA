void generate(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int ind, int k){
    if(temp.size() == k){
        ans.push_back(temp);
        return;
    }
    
    for(int i=ind; i<nums.size(); i++){
        temp.push_back(nums[i]);
        generate(ans, temp, nums, i+1, k);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> nums(n);
    vector<int> temp;
    
    for(int i=0; i<n; i++){
     nums[i] = i+1;
    }
    
    generate(ans,temp,nums,0,k);
    return ans;
}