class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;

        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }

        int x = pq.top()-1;
        pq.pop();
        int y = pq.top()-1;
        pq.pop();

        return x*y;
        
    }
};