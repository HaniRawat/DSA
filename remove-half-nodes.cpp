Node* solve(Node* root){
    if(root == NULL)
        return NULL;
        
    root->left = solve(root->left);
    root->right = solve(root->right);
    
    if(root->left == NULL && root->right == NULL)
        return root;
        
    if(root->left == NULL)
        return root->right;
        
    if(root->right == NULL)
        return root->left;
    
    return root;
}
Node *RemoveHalfNodes(Node *root)
{
   return solve(root);
}