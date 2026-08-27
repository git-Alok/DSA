class Twitter {
public:
unordered_map<int,unordered_set<int>>following;
unordered_map<int,vector<pair<int,int>>>tweets;
int time;
    Twitter() {
       time = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans;
          int count =0;
        for(int i=tweets[userId].size()-1;i>=0;i--){
            count++;
            pq.push(tweets[userId][i]);
            if(count>=10) break;
        }
        for(int followee : following[userId]){
            count =0;
            for(int i=tweets[followee].size()-1;i>=0;i--){
                count++;
                if(pq.size()<10)
                pq.push(tweets[followee][i]);
                else{
                    if(pq.top().first<tweets[followee][i].first)
                    {
                        pq.pop();
                        pq.push(tweets[followee][i]);
                    }
                }
                if(count>=10) break;
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
           return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return ;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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