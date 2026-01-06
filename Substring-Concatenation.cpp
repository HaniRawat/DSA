vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    map<string,int>h1;
    vector<int>v;
    int n=0;
    int l=B[0].size();
    for(auto a:B){
        h1[a]++;
        n++;
    }

    for(int i=0;i<A.size();i++){
       if(h1.find(A.substr(i,l))!=h1.end()){
        map<string,int>h;
        h.insert(h1.begin(),h1.end());
        int f=i;
        int sum=0;
        while(h[A.substr(f,l)]>0){
            h[A.substr(f,l)]--;
            sum++;
            f+=l;
        }
        if(sum==n)v.push_back(i);
       }
    }
    return v;
}