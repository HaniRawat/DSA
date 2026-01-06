class Solution {

public:
    int n, ans = 0;
    int maximumGood(vector<vector<int>>& S) {
        n = size(S);
        string curr = "";
        curr.reserve(n);
        dfs(S,curr,0,0);
        return ans;
    }

    void dfs(vector<vector<int>>& S, string& curr, int i, int cnt){
        if(i == n){
            if(valid(S,curr)) // if valid, update ans to store maximum good person found till now
                ans = max(ans,cnt);
                return;
        }

        curr.append(1,'0');
        dfs(S,curr,i+1,cnt); // assuming ith person is bad
        curr.back() = '1';
        dfs(S,curr,i+1,cnt+1); // assuming ith person is good
        curr.pop_back();
    }

    bool valid(vector<vector<int>>& S, string& curr){
        for(int i=0; i<n; i++){
            if(curr[i] == '1'){
                for(int j=0; j<n; j++){
                    if(S[i][j] != 2 && S[i][j] != curr[j]-'0'){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};