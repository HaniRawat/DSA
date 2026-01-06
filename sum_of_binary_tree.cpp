void solve(Node* root, long int& sum){
    if(root == NULL)
        return;
    solve(root->left, sum);
    sum += root->key;
    solve(root->right, sum);
}
long int sumBT(Node* root)
{
    long int sum = 0;
    solve(root, sum);
    return sum;
}