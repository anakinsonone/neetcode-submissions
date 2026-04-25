class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stak;

        for(int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while(!stak.empty() && t > stak.top().first) {
                auto top = stak.top();
                stak.pop();
                res[top.second] = i - top.second;
            }
            stak.push({t, i});
        }

        return res;
    }
};
