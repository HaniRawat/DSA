bool isPalindrome(string s){
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] != s[n-i-1])
            return false;
    }
    return true;
}

void recurse(vector<vector<string>>&ans, vector<string>row,string&A, int index){
    if(index == A.size()){
        ans.push_back(row);
        return;
    }
    
    string s = "";
    for(int i=index; i<A.size(); i++){
        s += A[i];
        if(isPalindrome(s)){
            row.push_back(s);
            recurse(ans,row,A,i+1);
            row.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>>ans;
    vector<string>curr;
    recurse(ans,curr,A,0);
    return ans;
}