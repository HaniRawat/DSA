int maxNodeLevel(Node *root)
{
    int count = -1;
    
    if(root == NULL)
        return 0;
    
    queue<Node*>q;
    int maxi = 0;
    int ans = 0;
    
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        count++;
        
        if(size > maxi){
            maxi = size;
            ans = count;
        }
        
        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left)
                q.push(temp->left);
                
            if(temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}