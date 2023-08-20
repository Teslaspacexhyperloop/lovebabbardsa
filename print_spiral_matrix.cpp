
leetcode 54

    class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int startrow = 0;
        int endrow = row - 1;
        int startcol = 0;
        int endcol = col - 1;
        int count = (row) * (col);

        int count1 = 0;
        while (count1 < count)
        {
            for (int i = startcol; count1 < count && i <= endcol; i++)
            {
                ans.push_back(matrix[startrow][i]);
                count1++;
            }
            startrow++;

            for (int i = startrow; count1 < count && i <= endrow; i++)
            {
                ans.push_back(matrix[i][endcol]);
                count1++;
            }
            endcol--;

            for (int i = endcol; count1 < count && i >= startcol; i--)
            {
                ans.push_back(matrix[endrow][i]);
                count1++;
            }
            endrow--;

            for (int i = endrow; count1 < count && i >= startrow; i--)
            {
                ans.push_back(matrix[i][startcol]);
                count1++;
            }
            startcol++;
        }
        return ans;
    }
};