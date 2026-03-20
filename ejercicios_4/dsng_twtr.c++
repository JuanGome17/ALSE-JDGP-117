#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Twitter {
private:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> followers;
public:
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
vector<int> getNewsFeed(int userId) {
    vector<pair<int,int>> allTweets;
    for (auto& tweet : tweets[userId]) {
        allTweets.push_back(tweet);
    }
    for (int followeeId : followers[userId]) {
        for (auto& tweet : tweets[followeeId]) {
            allTweets.push_back(tweet);
        }
    }
    sort(allTweets.begin(), allTweets.end(), greater<pair<int,int>>());
    vector<int> feed;
    for (int i = 0; i < allTweets.size() && i < 10; i++) {
        feed.push_back(allTweets[i].second);
    }
    return feed;
}
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.postTweet(1, 3);

    twitter.postTweet(2, 10);
    twitter.postTweet(2, 20);
    twitter.follow(1, 2);
    vector<int> feed = twitter.getNewsFeed(1);
    cout << "Feed del usuario 1:" << endl;
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;
    twitter.unfollow(1, 2);
    feed = twitter.getNewsFeed(1);
    cout << "Feed despues de unfollow:" << endl;
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;
    return 0;
}