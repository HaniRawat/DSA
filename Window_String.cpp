string Solution::minWindow(string A, string B) {
    int n = A.size(), m = B.size();
    
    if(m > n)
        return "";
    unordered_map<char,int>mp;
    
    for(char ch : B){
        mp[ch]++;
    }
    
    int left = 0, right = 0, cnt = 0, ans = 1e9, si = -1;
    while(right < n){
        if(mp[A[right]] > 0)
            cnt++;
        mp[A[right]]--;
        
        while(cnt == m){
            if((right - left + 1) < ans){
                ans = (right-left+1);
                si = left;
            }
            mp[A[left]]++;
            if(mp[A[left]] > 0)
                cnt--;
            left++;
        }
        right++;
    }
    if(si == -1)
        return "";
    return A.substr(si,ans);
}
