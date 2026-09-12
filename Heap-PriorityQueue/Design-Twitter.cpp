#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <math.h>

#include <cassert>
using namespace std;

class Twitter {
public:
    struct compare{
                bool operator()(pair<int, int> a, pair<int, int> b){
                    return a.first<b.first;
                }
    };
    class Tweeter{
        public:
        
        unordered_set<int> following;
        vector<pair<int, int>>  tweets;
    };
    int counter=0;
    unordered_map<int, Tweeter> users;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back({counter, tweetId});
        counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare > pq;
        Tweeter curr=users[userId];//specific tweeter with field following, and tweets
        for(int i=0; i<curr.tweets.size(); i++){
            pq.push(curr.tweets[i]);
        }
        for(int followeeId : curr.following){

            for(auto tweet : users[followeeId].tweets){
                pq.push(tweet);
            }
        }
        int z=pq.size();
        vector<int> ans;
        for(int i=0; i<min(z, 10); i++){
            pair<int, int> temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].following.erase(followeeId);
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);

    vector<int> feed1 = twitter.getNewsFeed(1);
    for (int tweet : feed1) {
        cout << tweet << " ";
    }
    cout << endl;
    // Expected: 5


    twitter.follow(1, 2);

    twitter.postTweet(2, 6);

    vector<int> feed2 = twitter.getNewsFeed(1);
    for (int tweet : feed2) {
        cout << tweet << " ";
    }
    cout << endl;
    // Expected: 6 5


    twitter.unfollow(1, 2);

    vector<int> feed3 = twitter.getNewsFeed(1);
    for (int tweet : feed3) {
        cout << tweet << " ";
    }
    cout << endl;
    // Expected: 5

    return 0;
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */