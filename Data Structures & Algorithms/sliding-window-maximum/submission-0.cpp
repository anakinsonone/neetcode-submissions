class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) {
            return nums;
        }

        int l = 0, r = k - 1;
        vector<int> maximums;
        while(r < nums.size()) {
            priority_queue<int> pq;
            for(int i = l; i <= r; i++) {
                pq.push(nums[i]);
            }

            maximums.push_back(pq.top());

            while(pq.size()) {
                pq.pop();
            }

            l++;
            r++;
        }

        return maximums;
    }
};
