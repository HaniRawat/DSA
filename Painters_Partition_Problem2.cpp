//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool isValid(vector<int>arr, int barrier, int k){
        int pages = 0;
        int studentNo = 1;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > barrier)
                return false;
            if(pages + arr[i] <= barrier)
                pages += arr[i];
            else{
                pages = arr[i];
                studentNo++;
            }
        }
        return studentNo <= k;
    }
    
    int minTime(vector<int>& arr, int k) {
        
        int n = arr.size();
        int ans = -1;
        int low = 0, high = 0;
        
        for(int i : arr){
            low = max(i, low);
            high += i;
        }
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(isValid(arr, mid, k)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends