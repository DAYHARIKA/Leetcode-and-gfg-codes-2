class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int low=0;
        int high=n-1;
        int area=0;
        while(low < high){

            if(height[low] <= height[high]){
              area=max(area,height[low]*(high-low));
              low++;
            }else{
              area=max(area,height[high]*(high-low));
              high--;
            }
        }
        return area;
    }
};