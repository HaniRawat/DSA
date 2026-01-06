int countRev (string s)
{
    int n = s.length();
    if(n&1) 
        return -1;
        
    int openBracket = 0;
    int closeBracket = 0;
    
    for(int i=0; i<n; i++){
        if(s[i] == '{')
            openBracket++;
        if(openBracket == 0 && s[i] == '}')
            closeBracket++;
        if(s[i] == '}' && openBracket!=0)
            openBracket--;
    }
    
    return ceil(openBracket/2.0) + ceil(closeBracket/2.0);
}