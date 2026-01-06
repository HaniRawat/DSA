//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
        arr[rear++] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        if(front == rear)
            return -1;
        else{
            int ans = arr[front];
            front++;
            return ans;
        }
}