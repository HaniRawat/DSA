vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    set<vector<int>>ans;
    
    for(int i=0; i<A.size(); i++){
        
        for(int j=i+1; j<A.size(); j++){
            int tar = B - A[i] - A[j];
            
            int x = j+1;
            int y = A.size()-1;
            
            while(x<y){
                if(tar > A[x]+A[y])
                    x++;
                else if(tar < A[x]+A[y])
                    y--;
                
                if(tar == A[x]+A[y]){
                    if(x != y)
                        ans.insert({A[i], A[j],A[x],A[y]});
                    x++;
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(),ans.end());
}