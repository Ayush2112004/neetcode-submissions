class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int x:nums){
            um[x]++;
        }
        for(auto& it:um){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            pair<int,int> top=pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        return res;
    }
};
