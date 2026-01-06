class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
        vector<int> ans;
        queue<Node*>q;
        q.push(root);
        int maxi = INT_MIN;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* front = q.front();
                q.pop();
                
                maxi = max(maxi, front->data);
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(maxi);
            maxi = INT_MIN;
        }
        return ans;
    }
};