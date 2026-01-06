long long int maxSum(int arr[], int n)
{
    long long int ans = 0;
    
    sort(arr,arr+n);
    int i = 0;
    int j = n-1;
    
    while(i < j){
        ans += abs(arr[i] - arr[j]) + abs(arr[i + 1] - arr[j]);
        i++;
        j--;
    }
    ans += abs(arr[i] - arr[0]);
    return ans;
}