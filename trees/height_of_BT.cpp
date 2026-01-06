class Solution{
    public:
    //Function to find the height of a binary tree.

    int height(struct Node* node){
        if(node == NULL)
            return 0;
        return max(1+height(node->left), 1+height(node->right));
    }
};