class Solution {
public:
    int maxElement(vector<int>& arr){
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    long long time(vector<int>& piles,int banana){
        int n=piles.size();
        long long t=0;
        for(int i=0;i<n;i++){
           t += (piles[i] + banana - 1) / banana;
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=maxElement(piles);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(time(piles,mid)<=h){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};