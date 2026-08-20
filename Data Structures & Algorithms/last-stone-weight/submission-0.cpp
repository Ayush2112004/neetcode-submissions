class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i:stones){
            pq.push(i);
        }
        if(stones.size()==1){
            return stones[0];
        }
        if(stones.size()==2){
            return abs(stones[0]-stones[1]);
        }
        while(pq.size()>1){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            pq.push(top1-top2);
        }
        return pq.top();
    }
};
