//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	vector<string>ans;
	queue<string>q;
	
	q.push("1");
	
	for(int i=0; i<N; i++){
	    string curr = q.front();
	    q.pop();
	    ans.push_back(curr);
	    q.push(curr+"0");
	    q.push(curr+"1");
	}
	return ans;
}