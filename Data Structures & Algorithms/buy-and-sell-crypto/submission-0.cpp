class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPr = INT_MIN;
        for(int i = 0; i < prices.size(); i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                maxPr = max(maxPr, profit);
            }
        }
        if (maxPr < 0) return 0;
        else return maxPr;
    }
};
