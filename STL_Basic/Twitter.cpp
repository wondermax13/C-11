class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        
        if(followers.find(userId) != followers.end()) {
            
            for(auto follower : followers[userId]) {
                
                auto userTweet = userTweets.find(follower);
                if(userTweet != userTweets.end()) {
                    
                    //auto it = userTweets.find(tweetId);
                    
                    userTweets[follower].push(tweetId);
                    
                    if(userTweets[follower].size() > 10) {
                        
                        userTweets[follower].pop();
                    }
                }
            }
        }
        
        userTweets[userId].push(tweetId);
        if(userTweets[userId].size() > 10) {
            
            userTweets[userId].pop();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        vector<int> res;
        
        auto it = userTweets.find(userId);
        if(it != userTweets.end()) {
            
            for(int i = 0; i < it->second.size(); i++) {
                
                res.push_back(it->second.front());
                it->second.pop();
            }
            //res = new vector<int>(it->second.rbegin(), it->second.rend());
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        
        followers[followeeId].push_back(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
        auto it = followers.find(followeeId);
        auto it2 = find(it->second.begin(), it->second.end(), followerId);
                        
        if(it2 != it->second.end()) {
            
            it->second.erase(it2);
        }
    }
    
private:
    unordered_map<int, vector<int>> followers;
    unordered_map<int, queue<int>> userTweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */