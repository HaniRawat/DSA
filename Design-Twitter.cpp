//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    vector<pair<int,int>>posts; //<userid,tweetid>
    unordered_map<int,unordered_set<int>> ump;

// <userid,<userid following these people in the unordered_set>>
    
    // Initialize your data structure here
    Twitter() {}

    // Compose a new tweet
    void postTweet(int userid, int tweetid) {
        posts.push_back({userid,tweetid});
    }
    
    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userid) {
        vector<int>tid;
        int cnt=0;
        for(int i=posts.size()-1;i>=0;i--)
        {
            if(posts[i].first==userid || ump[userid].find(posts[i].first)!=ump[userid].end()) // his tweet or his followee tweet
            {
                cnt++;
                tid.push_back(posts[i].second);
            }
            if(cnt>=10)
            break;
        }
        return tid;
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerid, int followeeid) {
        ump[followerid].insert(followeeid);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerid, int followeeid) {
        ump[followerid].erase(followeeid);
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends