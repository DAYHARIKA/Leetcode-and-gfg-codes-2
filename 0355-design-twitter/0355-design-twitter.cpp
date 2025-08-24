class node{
    public:
    int timee;
    int tweet;
    int i;
    int uid;
    node(int t,int tw,int ind,int u){
        timee=t;
        tweet=tw;
        i=ind;
        uid=u;
    }
};
class compare{
    public:
    bool operator()(node a,node b){
        return a.timee < b.timee;
    }
};
class Twitter {
    int time;
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int,vector<pair<int,int>>> posts;
public:
    Twitter() {
       time=0; 
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<node,vector<node>,compare> pq;
        unordered_set<int> uset=follows[userId];
        uset.insert(userId);

        for(int it:uset){
           auto &folowe=posts[it];

           if(!folowe.empty()){
              int i=folowe.size()-1;
              pq.push({folowe[i].first,folowe[i].second,i,it});
           }
        }

        vector<int> feed;
        while(!pq.empty() && feed.size() < 10){
            auto it=pq.top();
            pq.pop();

            feed.push_back(it.tweet);
            auto &folowe=posts[it.uid];
            int i=it.i;

            if(i-1 >= 0){
                pq.push({folowe[i-1].first,folowe[i-1].second,i-1,it.uid});
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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