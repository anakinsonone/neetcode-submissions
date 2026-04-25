class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns = matrix[0].size();
        int low = 0, high = (rows * columns) - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = (mid / columns), column = (mid % columns);
            int num = matrix[row][column];

            if (num == target) {
                return true;
            } else if (target < num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
