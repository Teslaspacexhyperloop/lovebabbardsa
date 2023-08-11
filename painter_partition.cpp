coding ninjas

    painter partition

    bool
    f(vector<int> &boards, int mid, int k)
{
    int n = boards.size();
    int paintercount = 1;
    int current = 0;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        current += boards[i];
        if (current > mid)
        {
            current = boards[i];
            paintercount++;
            if (paintercount > k || boards[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
    }

    int ans = 0;

    int s = 0;
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (f(boards, mid, k) == true)
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