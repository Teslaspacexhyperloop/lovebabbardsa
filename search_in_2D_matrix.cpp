leetcode 74

    You are given an m x n integer matrix matrix with the following two properties :

    Each row is sorted in non -
    decreasing order.The first integer of each row is greater than the last integer of the previous row.Given an integer target,
    return true if target is in matrix or false otherwise.

                                          You must write a solution in
                                          O(log(m * n)) time complexity.

                                          class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int j = col - 1; // col ke liye
        int i = 0;       // row ke liye

        bool flag = false;

        while (i < row && j >= 0)
        {

            int num = matrix[i][j];
            if (target > num)
            {
                i++;
            }
            else if (target == num)
            {
                flag = true;
                break;
            }
            else
            {
                j--;
            }
        }

        return flag;
    }
};