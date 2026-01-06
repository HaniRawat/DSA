class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq;

        for(long long i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }
        while(k > 0){
            long long max_num = pq.top();
            pq.pop();
            pq.push(floor(sqrt(max_num)));
            k--;
        }

        long long ans = 0;

        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};