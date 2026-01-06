class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      queue<Node*>q;
      vector<int> ans;
      
      ans.push_back(root->data);
      q.push(root);
      
      while(!q.empty()){
          Node* temp = q.front();
          q.pop();
          
          if(temp->left){
            ans.push_back(temp->left->data);
            q.push(temp->left);
          }
          if(temp->right){
            ans.push_back(temp->right->data);
            q.push(temp->right);
          }
          
      }
      return ans;
    }
};