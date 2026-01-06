//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   Given contraint is  : 1 <= K <= 500.

//     Upon arranging the glasses in the form of a pascal triangle , we get the following pattern :
//     1 + 2 + 3 + . . . . . . + n >= 500 , where each number represents the number of glasses in repective row.
    
//     n * (n+1) / 2 >= 500 
    
//     n * (n+1) >= 1000
    
//     The smallest possible value of n is 32 .  (32*33 = 1056) 
    
//     So we don't need more than 32 rows to solve this problem.
    
    double waterOverflow(int poured, int row, int glass) {
        
        double triangle[32][32] = {0.0};
        triangle[0][0] = poured;
        
        for(int i=0; i<= row; i++){
            for(int j=0; j<= i; j++){
                
                if(triangle[i][j] > 1){
                    double half = (triangle[i][j] - 1)/2.0;
                    
                    triangle[i+1][j] += half;
                    triangle[i+1][j+1] += half;
                    triangle[i][j] = 1;
                }
            }
        }
        return triangle[row-1][glass-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends