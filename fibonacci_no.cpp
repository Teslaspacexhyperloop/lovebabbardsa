

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        int ans1 = 0;
        int ans2 = 1;
        int ans = 0;
        for (int j = 2; j <= n; j++)
        {
            ans = ans1 + ans2;
            ans1 = ans2;
            ans2 = ans;
        }
        return ans;
    }
};