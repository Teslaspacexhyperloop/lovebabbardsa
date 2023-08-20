
coding numjas

    Sample Input 1 : 2 3 4 1 2 3 4 5 6 7 8 9 10 11 12 4 4 1 2 4 5 3 6 8 10 11 12 13 15 16 14 9 7 Sample Output 1 : 1 5 9 10 6 2 3 7 11 12 8 4 1 3 11 16 14 12 6 2 4 8 13 9 7 15 10 5

#include <bits/stdc++.h>
    vector<int>
    wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int i = 0; i < mCols; i++)
    {
        for (int j = 0; j < nRows; j++)
        {
            if (i % 2 == 0)
            {
                ans.push_back(arr[j][i]);
            }
            else
            {
                ans.push_back(arr[nRows - j - 1][i]);
            }
        }
    }
    return ans;
}