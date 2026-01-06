class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int,int>>adj[n];
        int cnt = 0;

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>v(n,1e9);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        v[0] = 0;

        while(!pq.empty()){
            int pos = pq.top().second;
            int wt = pq.top().first;

            pq.pop();

            for(auto it: adj[pos]){
                if(v[it.first] > wt+it.second+1){
                    v[it.first] = it.second + wt + 1;
                    pq.push({v[it.first], it.first});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(maxMoves >= v[i])
                cnt++;
        }
        for(auto it: edges){
            int l1 = max(0,maxMoves-v[it[0]]), l2 = max(0,maxMoves - v[it[1]]);
            cnt += min(it[2], l1 + l2);
        }
        return cnt;
    }
};