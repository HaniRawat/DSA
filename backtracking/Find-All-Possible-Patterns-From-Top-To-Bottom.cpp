//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    
    bool isPossible(int x, int y, int n, int m, vector<vector<int>>& visited){
        if(x >= 0 && x < n && y >= 0 && y < m && visited[x][y] != 1)
            return true;
            
        return false;
    }

    void solve(int x, int y, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &ans, vector<vector<int>> &visited, vector<int>& store){
        if(x == n-1 && y == m-1){
            store.push_back(grid[x][y]);
            ans.push_back(store);
            
            store.pop_back();
            return;
        }
        
        visited[x][y] = 1;
        store.push_back(grid[x][y]);
        
        if(isPossible(x+1, y, n, m, visited)){
            solve(x+1,y,grid,n,m,ans,visited,store);
        }
        
        if(isPossible(x,y+1,n,m,visited)){
            solve(x,y+1,grid,n,m,ans,visited,store);
        }
        visited[x][y] = 0;
        
        store.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> store;
        vector<vector<int>> visited(n, vector<int>(m));
        
        solve(0, 0, grid, n, m, ans, visited, store);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends