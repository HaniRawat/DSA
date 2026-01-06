int Solution::majorityElement(const vector<int> &A) {
    int cnt = 0;
    int ele;
    
    for(int i=0; i<A.size(); i++){
        if(cnt == 0){
            ele = A[i];
            cnt = 1;
        }else{
            if(A[i] == ele)
                cnt++;
            else
                cnt--;
        }
    }
    return ele;
}
// hani