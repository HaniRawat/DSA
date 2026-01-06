//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
    public:
    int data;
    int row;
    int col;
    node(int data, int row, int col){
        this->data= data;
        this->row= row;
        this->col= col;
        
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data>b->data;
        
    }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int maxi= INT_MIN;
        int mini=INT_MAX;
        priority_queue<node*,vector<node*>,compare> pq;
        
        for(int i=0; i<k; i++){
            maxi= max(maxi, KSortedArray[i][0]);
            mini= min(mini, KSortedArray[i][0]);
            node* temp= new node(KSortedArray[i][0], i, 0);
            pq.push(temp);
            
        }
        int start= mini;
        int end= maxi;
        
        while(!pq.empty()){
            node* top= pq.top();
            //update minipq.
            pq.pop();
            mini= top->data;
            if(maxi-mini<end- start){
                start= mini;
                end= maxi;
                
            }
            
            // find maxi;
            if(top->col+1<n){
                maxi= max(KSortedArray[top->row][top->col+1], maxi);
               
               pq.push(new node(KSortedArray[top->row][top->col+1], top->row, top->col+1));
               
            }
            else{
                break;
            }
            
        }
       return make_pair(start, end);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends