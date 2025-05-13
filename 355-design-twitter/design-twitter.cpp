class Twitter {

  private:
    int timestamp;
    unordered_map<int, unordered_set<int>> followers; // user -> set of followees
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> list of (time, tweetId)

public:
 
    Twitter() {
       timestamp = 0;  
    }
    
    void postTweet(int userId, int tweetId) {
         tweets[userId].push_back({timestamp++, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        // Min heap with max size 10
        priority_queue<pair<int, int>> pq;

        // Add self
        followers[userId].insert(userId);

        for (int followee : followers[userId]) {
            auto &tw = tweets[followee];
            for (auto &t : tw) {
                pq.push(t);
            }
        }

        // Get top 10 most recent
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followers[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
         if (followers[followerId].count(followeeId)) {
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */