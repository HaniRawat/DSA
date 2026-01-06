//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    unordered_set<string> st;
    vector<string> res;
    
    void solve(int i, string &s, string &sen){
    if (i >= s.size())
    {
        res.push_back(sen);
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        string temp = s.substr(i, j - i + 1);
        if (st.find(temp) != st.end())
        {
            string str = sen;
            if (!sen.empty())
            {
                sen += " ";
            }
            sen += temp;
            solve(j + 1, s, sen);
            sen = str;
        }
    }
}
    vector<string> wordBreak(vector<string>& dict, string s) {
        
        for(string &str : dict){
            st.insert(str);
        }
        string sen = "";
        solve(0, s, sen);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        cin >> s;
        cin.ignore();
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends