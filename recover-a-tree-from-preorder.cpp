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
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,TreeNode*>mp;

        int n= traversal.size();

        for(int i = 0; i<n; ){
            int depth = 0;
            while(i<n && traversal[i] == '-'){
                i++;
                depth++;
            }

            string num = "";

            while(i<n && isdigit(traversal[i])){
                num += traversal[i];
                i++;
            }

            int number = stoi(num);

            TreeNode* node = new TreeNode(number);

            if(depth > 0){
                TreeNode* parent = mp[depth - 1];

                if(parent->left == NULL)
                    parent->left = node;
                else
                    parent->right = node;
            }
            mp[depth] = node;
        }
        return mp[0];
        
    }
};