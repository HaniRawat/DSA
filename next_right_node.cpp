class Solution
{
public:
    Node *nextRight(Node *root, int key)
    {
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                if(temp->data == key && i!=size-1){
                    return q.front();
                }
                
                if(temp->left)
                    q.push(temp->left);
                    
                if(temp->right)
                    q.push(temp->right);
                
            }
        }
        Node* node = new Node(-1);
        return node;
    }
};