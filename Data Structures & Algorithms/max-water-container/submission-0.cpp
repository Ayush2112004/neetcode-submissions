class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int area=INT_MIN;
        while(i<j){
            int bar=min(heights[i],heights[j]);
            area=max(area,bar*(j-i));
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};
