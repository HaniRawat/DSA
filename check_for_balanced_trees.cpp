class Solution{
    public:
    
    pair<bool,int> checkBalance(Node* root){
        if(root == NULL)
            return {true,0};
            
        auto left = checkBalance(root->left);
        auto right = checkBalance(root->right);
        
        bool balanced = left.first && right.first &&
        (abs(left.second - right.second) <= 1);
        
        int height = max(left.second , right.second)+1;
        
        return {balanced, height};
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return checkBalance(root).first;
    }
};