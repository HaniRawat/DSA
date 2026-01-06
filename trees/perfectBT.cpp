class Solution
{
public:
    bool isPerfect(Node *root)
    {
        int level = 0;
        queue<Node*> q;
        
        if(root != NULL)
            q.push(root);
            
        while(!q.empty()){
            int n = q.size();
            
            if(n != pow(2,level))
                return false;
            level++;
            
            for(int i=0; i<n; i++){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return true;
    }
};