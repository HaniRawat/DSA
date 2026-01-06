void addel(TreeNode* root, TreeNode* root1){
     TreeNode* temp = root->right;
     root->right = root1;
    while(root1->right!=NULL){
        root1 = root1->right;
    }
    root1->right = temp;
 }
 
 void flattened(TreeNode* root){
     while(root!=NULL){
         if(root->left){
             addel(root,root->left);
             root->left = NULL;
         }
         root = root->right;
     }
 }
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    flattened(A);
    return A;
}