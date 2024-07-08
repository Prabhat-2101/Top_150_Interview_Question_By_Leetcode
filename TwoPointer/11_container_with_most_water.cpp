class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int start = 0,end = height.size()-1;
        while(start < end){
            int area = (end-start) * min(height[start],height[end]);
            max_area = max(area,max_area);
            if(height[start]<height[end]) start += 1;
            else end -= 1;
        }
        return max_area;
    }
};