class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        while(r<k){
            pq.push({nums[r],r});
            r++;
        }
        res.push_back(pq.top().first);
        while(r<n){
            pq.push({nums[r],r});
            l++;
            pair<int,int> top=pq.top();
            while(!pq.empty() && pq.top().second<l){
                pq.pop();
            }
            
            
            res.push_back(pq.top().first);
            r++;
        }
        return res;
    }
};
