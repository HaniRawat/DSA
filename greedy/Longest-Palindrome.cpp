class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int pairs = 0;

        map<char,int>ch;

        for(int i=0; i<n; i++){
            ch[s[i]]++;

            if(ch[s[i]] % 2 == 0)
                pairs++;
        }
        return pairs*2 == n ? n : pairs*2+1;
        
    }
};