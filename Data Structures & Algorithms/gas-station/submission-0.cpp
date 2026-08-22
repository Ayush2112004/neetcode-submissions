class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        int currGas=0;
        int totalGas=0;
        int totalCost=0;
        for(int i:gas){
            totalGas+=i;
        }
        for(int i:cost){
            totalCost+=i;
        }
        if(totalCost>totalGas){
            return -1;
        }
        for(int i=0;i<n-1;i++){
            currGas=currGas+gas[i]-cost[i];
            if(currGas<0){
                currGas=0;
                start=i+1;
            }
        }
        return start;
    }
};
