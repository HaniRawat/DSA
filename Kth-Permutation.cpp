void nextPermutation(vector<int>& nums, int k){
    if(k == 1)
        return;
    
    int i = nums.size()-2;
    
    while(i >= 0 && nums[i+1] <= nums[i]){
        i--;
    }
    
    if(i >= 0){
        int j = nums.size()-1;
        while(nums[j] <= nums[i]){
            j--;
        }
        swap(nums[j], nums[i]);
    }
    
    reverse(nums.begin()+i+1, nums.end());
    nextPermutation(nums,k-1);
    
}

string Solution::getPermutation(int A, int B) {
    vector<int>nums;
    
    for(int i=1; i<=A; i++){
        nums.push_back(i);
    }
    
    nextPermutation(nums,B);
    string ans;
    
    for(int i=0; i<A; i++){
        ans += to_string(nums[i]);
    }
    
    return ans;
}