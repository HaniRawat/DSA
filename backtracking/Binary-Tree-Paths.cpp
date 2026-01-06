/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPaths(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;
        if(!path.empty()) {
            path += "->";
        }
        path+=to_string(root->val);
        // If it's a leaf node, add the path to the list
       if (!root->left && !root->right ){
            ans.push_back(path);
        }else{
            // Otherwise, continue to explore the left and right subtree
            findPaths(root->left, path, ans);
            findPaths(root->right, path, ans);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root != NULL){
            findPaths(root, "", ans);
        }
        return ans;
    }
};