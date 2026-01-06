int Solution::colorful(int A) {
    unordered_map<long long, int> mp;
    string s = to_string(A);
    int n = s.length();
    
    if(n==1)
        return 1;
    
    for(int i=0; i<n; i++){
        long long prod = 1;
        for(int j=i; j<n; j++){
            prod *= (long long)(s[j] - '0');
            if(mp.find(prod) != mp.end())
                return 0;
            mp[prod]++;
        }
    }
    return 1;
}