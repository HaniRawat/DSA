vector<int> Solution::solve(TreeNode* root) {
    vector<int>ans;
    
    queue<TreeNode*> q;
    
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        
        while(temp != NULL){
            if(temp->left != NULL)
                q.push(temp->left);
                
            ans.push_back(temp->val);
            temp = temp->right;
        }
    }
    return ans;
}