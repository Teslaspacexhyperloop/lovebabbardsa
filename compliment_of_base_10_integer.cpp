Leetcode 1009 
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

                                                                                                       For example,
    The integer 5 is "101" in binary and its complement is "010" which is the integer 2. Given an integer n, return its complement.

    class Solution
{
public:
    int d2b(int n)
    {
        int ans = 0;
        int i = 0;
        while (n != 0)
        {
            int digit = n & 1;
            if (digit == 0)
            {
                digit = 1;
            }
            else
            {
                digit = 0;
            }
            ans = digit * pow(2, i) + ans;
            i++;
            n = n >> 1;
        }
        return ans;
    }
    int bitwiseComplement(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        return d2b(n);
    }
};