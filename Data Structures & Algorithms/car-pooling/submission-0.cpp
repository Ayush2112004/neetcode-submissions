class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;
        int n=trips.size();
        for(int i=0;i<n;i++){
            int passenger=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            events.push_back({from,passenger});
            events.push_back({to,-passenger});
        }
        sort(events.begin(),events.end());
        int passenger=0;
        for(int i=0;i<events.size();i++){
            passenger+=events[i].second;
            if(passenger>capacity){
                return false;
            }
        }
        return true;
    }
};