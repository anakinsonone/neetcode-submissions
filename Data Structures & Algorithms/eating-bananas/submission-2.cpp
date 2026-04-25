class Solution {
public:
    int hoursToEatAllBananas(std::vector<int> &piles, int rate) {
        int totalHours = 0;
        for (int bananas : piles) {
            totalHours += (bananas / rate);
            if (bananas % rate != 0) {
            totalHours++;
            }
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());
        int low = 1, high = piles[piles.size() - 1];
        int minRate = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int hoursTaken = hoursToEatAllBananas(piles, mid);

            if (hoursTaken <= h) {
            minRate = std::min(mid, minRate);
            high = mid - 1;
            } else {
            low = mid + 1;
            }
        } 

        return minRate;
    }
};
