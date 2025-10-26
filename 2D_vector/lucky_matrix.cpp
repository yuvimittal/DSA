// Given an m x n matrix of distinct numbers,
//  return all lucky numbers in the matrix in any order.

// A lucky number is an element of the matrix such that it is
//  the minimum element in its row and maximum in its column.

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ans;

        for (int i = 0; i < rows; i++) {
            int rowMin = INT_MAX;
            int colIndex = -1;

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    colIndex = j;
                }
            }

            bool isMaxInCol = true;
            for (int k = 0; k < rows; k++) {
                if (matrix[k][colIndex] > rowMin) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMaxInCol)
                ans.push_back(rowMin);
        }

        return ans;
    }
};
