class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char , int> count;
            queue<char> q;
            string str = "";
            
            for(int i = 0; i < A.length();i++ ){
                count[A[i]]++;
                q.push(A[i]);
                
               while(!q.empty() && count[q.front()] > 1){
                     q.pop();
               }
                if(q.empty()){
                    str += "#"; 
                }
                else{
                    str += q.front(); 
                }
            }
            return str;
		}

};

