class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x=false;
        bool y=false;
        bool z=false;
        for(auto &t:triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2]){
                continue;
            }//any value greater then target cannot form that so we skip that triplet if that contain value greate then target
            if(t[0]==target[0]) x=true;
            if(t[1]==target[1]) y=true;
            if(t[2]==target[2]) z=true;
        }
        return (x && y && z);
    }
};
