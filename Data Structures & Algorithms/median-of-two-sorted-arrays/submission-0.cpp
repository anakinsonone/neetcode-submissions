class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size(), n = nums2.size();
       int l = 0, r = 0;
       vector<int> merged;

       while(l < m && r < n) {
            if(nums1[l] <= nums2[r]) {
                merged.push_back(nums1[l]);
                l++;
            } else {
                merged.push_back(nums2[r]);
                r++;
            }
       } 
       while(l < m) {
            merged.push_back(nums1[l]);
            l++;
       }
       while(r < n) {
            merged.push_back(nums2[r]);
            r++;
       }

       int index = merged.size() / 2;
       if(merged.size() % 2 != 0) {
            return double(merged[index]);
       } else {
            int n1 = merged[index];
            int n2 = merged[index - 1];
            return double((n1 + n2) / 2.0);
       }
    }
};
