class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_map<int, int>mpp;
       for(int n: nums) {
        if(mpp[n]) {
            return n;
        }
        mpp[n]++;
       } 
    }
};
