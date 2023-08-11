#include <bits/stdc++.h>
int floorSqrt(int n)
{
    int s = 1;
    int e = (n / 2);
    int mid = s + (e - s) / 2;
    int ans = 0;
    if (n == 0 || n == 1)
    {
        return n;
    }
    int num = -1;
    while (s <= e)
    {

        if (INT_MAX / mid <= mid)
        {
            e = mid - 1;
        }
        else
        {
            num = mid * mid;
            ;

            if (num == n)
            {
                ans = mid;
                break;
            }
            else if (num > n)
            {
                e = mid - 1;
            }
            else
            {
                ans = mid;
                s = mid + 1;
            }
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}