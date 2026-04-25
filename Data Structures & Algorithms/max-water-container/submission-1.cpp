class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int l = 0, r = heights.size() - 1;
        while(l < r) {
            int water = (r - l) * min(heights[l], heights[r]);
            maxWater = max(maxWater, water);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return maxWater;
    }
};
