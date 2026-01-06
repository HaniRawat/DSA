class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;

        for(int i=0; i<amount.size(); i++){
            pq.push(amount[i]);
        }
        int ans = 0;
        while(pq.top() != 0){
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            a--;
            b--;

            pq.push(a);
            pq.push(b);
            ans++;
        }
        return ans;
    }
};