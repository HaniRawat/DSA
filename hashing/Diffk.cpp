int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int,int>mp;
    for(int x : A){
        if(mp.find(x+B) == mp.end() && mp.find(x-B) == mp.end())
            mp[x]++;
        else
            return 1;
    }
    return 0;
}