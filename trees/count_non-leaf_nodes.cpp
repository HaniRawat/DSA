class Solution {
  public:
  
    void solve(Node* root, int& count){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        count++;
        solve(root->left, count);
        solve(root->right, count);
    }
    int countNonLeafNodes(Node* root) {
        int count = 0;
        solve(root, count);
        return count;
    }
};