class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int , int>mp;
        for(auto it: s){
            mp[it]++;
        }
        char x = 'A';
        for(char it : s){
            if(mp[it] == 1){
                x = it;
                break;
            }
        }
        if(x == 'A') 
            return -1;

        for(int i=0; i<s.size(); i++){
            if(s[i] == x)
                return i;
        }
        return -1;
    }
};