

coding ninjas

    bool
    f(vector<int> &stalls, int mid, int k)
{
    bool ans = false;
    int n = stalls.size();
    int cowcount = 1;
    int currentdistsnce = stalls[0];
    for (int i = 1; i < n; i++)
    {
        int dist = stalls[i] - currentdistsnce;
        if (dist >= mid)
        {
            cowcount++;
            currentdistsnce = stalls[i];
            if (cowcount == k)
            {
                ans = true;
                break;
            }
        }
    }

    return ans;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    int ans = 0;
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls[n - 1];
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (f(stalls, mid, k) == true)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}