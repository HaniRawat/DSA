class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        int dirs[] = {-1, 0, 1, 0, -1};
        priority_queue<tuple<int, int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        
        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();
            if (time > dp[r][c]) continue;
            if (r == m-1 && c == n-1) return time;
            
            for (int d = 0; d < 4; ++d) {
                int nr = r + dirs[d];
                int nc = c + dirs[d+1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;
                int earliest_time = time+1;
                if (grid[nr][nc] > time + 1) {
                    int diff = grid[nr][nc] - (time+1);
                    if (diff % 2) ++diff;
                    earliest_time = time+1+diff;
                }
                if (earliest_time < dp[nr][nc]) {
                    dp[nr][nc] = earliest_time;
                    pq.push({earliest_time, nr, nc});
                }
            }
        }
        return -1;
    }
};