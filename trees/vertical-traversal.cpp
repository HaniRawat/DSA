vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>>ans;
    
    if(!root)
        return ans;
        
    map<int,vector<int>>mp;
    queue<pair<TreeNode*, int>>q;
    
    q.push({root,0});
    
    while(!q.empty()){
        auto node = q.front().first;
        int dist = q.front().second;
        
        q.pop();
        
        mp[dist].push_back(node->val);
        
        if(node->left)
            q.push({node->left, dist-1});
            
        if(node->right)
            q.push({node->right,dist+1});
    }
    
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}