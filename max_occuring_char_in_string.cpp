

class Solution
{
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        vector<int> m(26, 0);
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            m[str[i] - 'a']++;
        }

        char ch;
        int maxi = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (m[i] >= maxi)
            {
                int num = 97 + i;
                ch = (char)num;
                maxi = max(maxi, m[i]);
            }
        }

        return ch;
    }
};