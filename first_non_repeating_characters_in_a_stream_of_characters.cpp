string Solution::solve(string a) {
    queue<char>q;
    unordered_map<char,int>mp;
    string ans = "";
    
    for(int i=0; i<a.size(); i++){
        mp[a[i]]++;
        q.push(a[i]);
        
        while(!q.empty() && mp[q.front()] > 1){
            q.pop();
        }
        
        if(q.empty())
            ans += '#';
        else
            ans += q.front();
    }
    return ans;
}
