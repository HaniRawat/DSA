class Solution
{
public:
    vector<Node *> nodesAtOddLevels(Node *root)
    {
        queue<Node*>q;
        q.push(root);
        
        int level = 1;
        vector<Node*> ans;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                
                if(level & 1)
                    ans.push_back(curr);
                
                if(curr->left)
                    q.push(curr->left);
                    
                if(curr->right)
                    q.push(curr->right);
            }
            level++;
        }
        return ans;
    }
};