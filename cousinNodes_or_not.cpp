bool parent(Node* root, int a, int b) {
    if(root==NULL)
        return 0;
    
    if(root->left && root->right) {
        if(root->left->data == a && root->right->data == b) 
            return 1;
        
        if(root->left->data == b && root->right->data == a) 
            return 1;
        
    }
    
    return parent(root->left,a,b) || parent(root->right,a,b);
}
bool isCousins(Node *root, int a, int b)
{
   queue<Node*>q;
   q.push(root);
   
   int level = 0;
   int l1 = -1, l2 = -1;
   
   while(!q.empty()){
       int size = q.size();
       for(int i = 0; i<size; i++){
           Node* temp = q.front();
           q.pop();
           
            if(temp->data == a)
                l1 = level;
            
            if(temp->data == b) 
                l2 = level;
           
            if(temp->left) 
                q.push(temp->left);
               
            if(temp->right) 
                q.push(temp->right);
           
       }
       level++;
       
        if(l1 != l2)
            return 0;
        
        if(l1 != -1 && l2 != -1)
            break;
   }
   
   if(l1 == -1 && l2 == -1)
    return 0;
    
    return !parent(root,a,b);
}
