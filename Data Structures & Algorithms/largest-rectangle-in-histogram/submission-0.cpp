class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int height = heights[i];
            int count = 1;
            int left = i - 1, right = i + 1;

            while(left >= 0 && heights[left] >= height) {
                count++;
                left--;
            }
            while(right < n && heights[right] >= height) {
                right++;
                count++;
            }

            int area = height * count;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
