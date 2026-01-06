int Solution::isMatch(const string s, const string p) {
    int n = s.size();
    int m = p.size();
    
    vector<int>prev(m+1, 0);
    prev[0] = 1;
    
    for(int j=1; j<m+1; j++){
        if(p[j-1] == '*')
            prev[j] = 1;
        else 
            break;
    }
    
    for(int i=1; i<n+1; i++){
        vector<int>curr(m+1, 0);
        for(int j=1; j<m+1; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?')
                curr[j] = prev[j-1];
            else if(p[j-1] == '*')
                curr[j] = curr[j-1]||prev[j];
            else
                curr[j] = 0;
        }
        
        prev = curr;
    }
    return prev[m];
}