int DFS(int node,vector<int> &vis, vector<int> adj[],int &count)
{
vis[node]=1;
int size=1;
for(auto it:adj[node])
{
if(!vis[it])
size+=DFS(it,vis,adj,count);
}
if(size%2==0)
count++;
return size ;
}
int Solution::solve(int A, vector<vector<int> > &B) {
vector<int> adj[A+1];
for(int i=0;i<B.size();i++)
{
int node1=B[i][0];
int node2=B[i][1];
adj[node1].push_back(node2);
adj[node2].push_back(node1);
}
vector<int> vis(A+1,0);

int count=0;
for(int i=1;i<=A;i++)
{
int p=0;//For each connected component find the number of edges
if(!vis[i])
{
DFS(i,vis,adj,p);
count+=p-1;// 1 is subtracted to as whenever you find the number of edges by calling the function( returns the number of nodes which have even size), then root always gets added for individual connected components.
}
}
return count;
}