int deepest(Node* root){
    if(root == NULL)
        return 0;
    
    queue<Node*>q;
    q.push(root);
    int ans = 0;
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        
        ans = front->data;
        
        if(front->left)
            q.push(front->left);
        if(front->right)
            q.push(front->right);
    }
    return ans;
}

void deleteNode(Node* root, int val){
    if(root == NULL)
        return;
        
    if(root->left && root->left->data == val)
        root->left = NULL;
        
    if(root->right && root->right->data == val)
        root->right = NULL;
        
    deleteNode(root->left,val);
    deleteNode(root->right,val);
}

void replace(Node* root, int key, int val){
    if(root == NULL)
        return;
    
    if(root->data == key)
        root->data = val;
    
    replace(root->left, key, val);
    replace(root->right, key, val);
}
struct Node* deletionBT(struct Node* root, int key)
{
    int deep = deepest(root);
    deleteNode(root,deep);
    replace(root,key,deep);
    return root;
}