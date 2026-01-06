void solve(Node* node, vector<int>& ans){
    if(node == NULL)
        return;
        
    if(node->left != NULL && node->right == NULL)
        ans.push_back(node->left->data);
     
    if(node->right != NULL && node->left == NULL)
        ans.push_back(node->right->data);
        
    solve(node->left,ans);
    solve(node->right,ans);
        
}
vector<int> noSibling(Node* node)
{
    vector<int>ans;
    
    solve(node,ans);
    if(ans.size() == 0)
        ans.push_back(-1);
    else
        sort(ans.begin(), ans.end());
        
    return ans;
}