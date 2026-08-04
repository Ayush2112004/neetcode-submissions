class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                int l=0;
                int r=m-1;
                while(l<=r){
                    int m=l+(r-l)/2;
                    if(matrix[mid][m]==target){
                        return true;
                    }
                    else if(matrix[mid][m]>target){
                        r=m-1;
                    }
                    else{
                        l=m+1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};
