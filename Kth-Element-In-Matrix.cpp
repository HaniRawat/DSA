//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

class Node{
  public:
  int data;
  int i;
  int j;
  
  Node(int data, int i, int j){
      this->data = data;
      this->i = i;
      this->j = j;
  }
};

class Compare{
  public:
  bool operator()(Node* a, Node* b){
   return a->data > b->data;   
  }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  
  priority_queue<Node*,vector<Node*>,Compare>pq;
  for(int i=0;i<n;i++)
  {
      pq.push(new Node(mat[i][0],i,0));
  }
  
  int count=0;
  while(!pq.empty())
  {
      auto top=pq.top();
      pq.pop();
      int data=top->data;
      int row=top->i;
      int col=top->j;
      
      count++;
      if(count==k)
      return data;
      
      if(col+1<n)
      pq.push(new Node(mat[row][col+1],row,col+1));
  }
  return -1;
}
