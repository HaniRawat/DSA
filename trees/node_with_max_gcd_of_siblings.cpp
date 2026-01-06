class Solution
{
public:
    int ans = 0, max_gcd = INT_MIN;
    int maxGCD( Node* root)
    {
       if(root == NULL)
        return 0;
        
        if(root->left && root->right){
            int k = __gcd(root->left->data, root->right->data);
            
            if(k > max_gcd || k == max_gcd && root->data > ans){
                max_gcd = k;
                ans = root->data;
            }
        }
        maxGCD(root->left);
        maxGCD(root->right);
        return ans;
    }
};