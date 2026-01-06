void solve(string &A, int index, string output, vector<string>& res, vector<string>& mapping){
    if(index >= A.length()){
        res.push_back(output);
        return;
    }
    
    int digit = A[index]-'0';
    string s = mapping[digit];
    
    for(auto i : s){
        output.push_back(i);
        solve(A,index+1,output,res,mapping);
        output.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string>mapping {"0","1","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string>res;
    
    solve(A,0,"",res,mapping);
    return res;
}