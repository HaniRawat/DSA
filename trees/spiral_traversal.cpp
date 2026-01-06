vector<int> findSpiral(Node *root)
{
    vector<int>result;
    if(root == NULL)
        return result;
    
    queue<Node*>q;
    q.push(root);
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int>ans(size);
        
        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();
            
            int index = leftToRight ? i:size-i-1;
            ans[index] = frontNode->data;
            
            if(frontNode->right)
                q.push(frontNode->right);
            if(frontNode->left)
                q.push(frontNode->left);
                
        }
        leftToRight = !leftToRight;
        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}