class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        unordered_map<int,int> um;
        for(int i:hand){
            um[i]++;
        }
        for(int i:hand){
            if(um[i]==0){
                continue;
            }
            for(int j=0;j<groupSize;j++){
                int next=i+j;
                if(um.find(next)==um.end()){
                    return false;
                }
                um[next]--;
            }
        }
        return true;
    }
};
