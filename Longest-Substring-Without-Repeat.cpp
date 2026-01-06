int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int>mp;
    int maxLen = 1;
    int j = 0;
    
    for(int i=0; i<A.length(); i++){
        mp[A[i]]++;
        while(mp[A[i]] > 1){
            mp[A[j]]--;
            j++;
        }
        maxLen = max(maxLen, i-j+1);
    }
    return maxLen;
}