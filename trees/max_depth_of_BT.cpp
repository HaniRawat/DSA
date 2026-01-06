class Solution{
  public:
    /*You are required to complete this method*/
    int solve(Node* root){
        if(root == NULL)
            return 0;
        return max(solve(root->left),solve(root->right))+1;
    }
    int maxDepth(Node *root) {
       return solve(root);
    }
};
