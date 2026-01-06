class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>st;
        queue<int>qans;
        
        int i=0;
        while(i<k){
            int ele = q.front();
            q.pop();
            st.push(ele);
            i++;
        }
        
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            qans.push(ele);
        }
        
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            qans.push(ele);
        }
        return qans;
    }
};