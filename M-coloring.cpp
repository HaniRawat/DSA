//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int node, int* color, vector<int> adj[], int curr_color){
        
        for(auto nbr : adj[node]){
            if(nbr == node){
                continue;
            }
            if(color[nbr] == curr_color){
                return false;
            }
        }
        return true;
        
    }

    bool solve(int node, int* color, vector<int> adj[], int n, int m){
        
        if(node == n){
            return true;
        }
        
        for(int i = 1; i <= m; i++){
            
            if(isSafe(node, color, adj, i)){
                
                color[node] = i;
                
                if(solve(node + 1, color, adj, n, m) == true){
                    return true;
                };
                
                color[node] = 0;
                
            }
            
        }
        
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> adj[n]; // array of vectors for storing edges between the nodes 
        int color[n] = {0}; // yeh hamara color store karegi ki ham kis node par kon sa color karenge 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        return solve(0, color, adj, n, m);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends