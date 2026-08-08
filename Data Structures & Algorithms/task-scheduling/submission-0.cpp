class Solution {
public:
    struct Compare{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.first<b.first;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        queue<pair<int,int>> q;
        vector<int> freq(26,0);
        for(char c:tasks){
            freq[c-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>=1){
                pq.push({freq[i],0});
            }
        }
        int time=0;
        while(!pq.empty() || !q.empty()){
            if(!q.empty() && time-q.front().second>=n+1){
                pq.push(q.front());
                q.pop();
            }
            if(!pq.empty()){
                pair<int,int> top=pq.top();
                pq.pop();
                top.first--;
                top.second=time;
                if(top.first>0){
                    q.push(top);
                }
            }
            time++;
        }
        return time;
    }
};
