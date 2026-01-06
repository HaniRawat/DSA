class Solution {
  public:
  
    // void solve(Node* node, vector<int>& ans){
    //     if(node == NULL)
    //         return;
            
    //     solve(node->left,ans);
    //     ans.push_back(node->data);
    //     solve(node->right,ans);
    // }
    // int getSize(Node* node) {
    //     vector<int>ans;
    //     solve(node,ans);
    //     return ans.size();
    // }
    
    void solve(Node* node, int& count) {
        if(node==NULL) return;
        count++;
        solve(node->left,count);
        solve(node->right,count);
    }
    int getSize(Node* node) {
       int count=0;
       solve(node,count);
       return count;
    }
};