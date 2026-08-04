class Solution {
public:
static bool compare(pair<int,double>& a,pair<int,double>& b){
    return a.first>b.first;
}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> arr;
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            arr.push_back({position[i],time});
        }
        sort(arr.begin(),arr.end(),compare);
        stack<double> st;
        int fleet=0;
        for(int i=0;i<n;i++){
            double time=arr[i].second;
            if(st.empty() || time>st.top()){
                st.push(time);
                fleet++;
            }
        }
        return fleet;
    }
};
