class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactions = 2*k;

        vector<int>prev(transactions+1, 0);
        vector<int>curr(transactions+1, 0);

        for(int index = n-1; index >= 0; index--){
            for(int transaction = transactions-1; transaction >= 0; transaction--){
                if(transaction % 2 == 0){
                    curr[transaction] = max(-prices[index]+prev[transaction+1], prev[transaction]);
                }
                else{
                    curr[transaction] = max(prices[index]+prev[transaction+1], prev[transaction]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};