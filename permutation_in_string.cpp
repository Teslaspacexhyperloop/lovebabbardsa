leetcode 567

    Given two strings s1 and s2,
    return true if s2 contains a permutation of s1, or false otherwise.

                                                        In other words,
    return true if one of s1's permutations is the substring of s2.

           Example 1 :

    Input : s1 = "ab",
            s2 = "eidbaooo" Output : true Explanation : s2 contains one permutation of s1("ba").

                                                        class Solution
{
public:
    bool f(vector<int> arr1, vector<int> arr2)
    {
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2)
        {
            return false;
        }
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);

        for (int i = 0; i < n1; i++)
        {
            int ind = s1[i] - 'a';
            arr1[ind]++;
        }

        for (int i = 0; i < n1; i++)
        {
            int ind = s2[i] - 'a';
            arr2[ind]++;
        }
        bool flag = false;
        for (int j = n1; j < n2; j++)
        {
            if (f(arr1, arr2))
            {
                flag = true;
                break;
            }
            else
            {
                int ind = s2[j - n1] - 'a';
                arr2[ind]--;
                int ind2 = s2[j] - 'a';
                arr2[ind2]++;
            }
        }

        if (f(arr1, arr2))
        {
            flag = true;
        }
        return flag;
    }
};