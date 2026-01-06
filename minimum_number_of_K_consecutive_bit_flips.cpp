class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        int size = nums.size();
        queue<int> record;

        for(int i=0; i<size; i++){
            int pivot = record.size() % 2 == 0 ? nums[i]:1-nums[i];

            if(pivot == 0){
                ans++;
                record.push(i+k-1);
            }
            if(!record.empty() && i == record.front())
                record.pop();
        }
        return record.empty()?ans:-1;
    }
};