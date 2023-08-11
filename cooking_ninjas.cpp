

cooking ninjas coding ninjas

#include <bits/stdc++.h>
    bool
    f(vector<int> &rank, int m, int mid)
{
    bool ans = false;
    bool flag = false;
    int n = rank.size();
    int chef_count = 1;
    for (int i = 0; i < n; i++)
    {
        int current_time = 0;

        int repeat = 1;
        while (current_time + (repeat * rank[i]) <= mid)
        {
            current_time += (repeat * rank[i]);
            repeat++;
            m--;
            if (m == 0)
            {
                ans = true;
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            break;
        }
        chef_count++;
        if (chef_count > n)
        {
            ans = false;
            break;
        }
    }
    return ans;
}
int minCookTime(vector<int> &rank, int m)
{
    int ans = 0;
    int n = rank.size();
    sort(rank.begin(), rank.end());
    int s = 0;
    int e = (rank[n - 1] * m * (m + 1)) / 2;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        bool res = f(rank, m, mid);
        if (res == true)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}
