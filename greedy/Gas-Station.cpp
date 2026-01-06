int Solution::canCompleteCircuit(const vector<int> &petrol, const vector<int> &distance) {
    int start = 0, total = 0, curr = 0;
    int n = petrol.size();
    
    for(int i=0; i<n; i++){
        curr += petrol[i] - distance[i];
        total += petrol[i] - distance[i];
        
        if(curr < 0){
            start = i+1;
            curr = 0;
        }
    }
    return total >= 0 ? start : -1;
}