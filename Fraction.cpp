string Solution::fractionToDecimal(int N, int D) {
    long long A = N;
    long long B = D;
    
    string ans = "";
    
    if((A<0 && B>0) || (B<0 && A>0))
        ans = "-";
    A = abs(A);
    B = abs(B);
    
    ans += to_string(A/B);
    long long a = A%B;
    
    if(a == 0)
        return ans;
    else
        ans += ".";
        
    map<long long, long long>m;
    vector<long long>v;
    
    long long bk=-1;  //To mark the breakpoint of recurring
    while(a) {
        if(m.find(a)==m.end()){
            v.push_back(a);
            m[a] = (a*10)/B;
            a*=10;
            a%=B;
        }
        else { 
            bk = a;
            break;
             }
    }
    if(a==0)
         for(int i=0;i<v.size();i++)
              ans+=to_string(m[v[i]]);
   
    else{
        for(int i=0;i<v.size();i++){
            if(v[i]==bk) ans+='(';
            ans+=to_string(m[v[i]]);
        }
        ans+=')';
    }
    return ans;
    
}