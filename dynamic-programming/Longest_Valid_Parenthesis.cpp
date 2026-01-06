int Solution::longestValidParentheses(string A) {
    stack<int>st;
    
    st.push(-1);
    int ans = 0;
    
    for(int i=0; i<A.size(); i++){
        if(A[i] == '(')
            st.push(i);
        else{
            st.pop();
            
            if(st.empty())
                st.push(i);
            else    
                ans = max(ans, i-st.top());
        }
    }
    return ans;
}