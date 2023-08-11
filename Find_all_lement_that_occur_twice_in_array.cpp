Leetcode 442

        Given an integer array nums of length n where all the integers of nums are in the range[1, n] and
        each integer appears once or
    twice,
    return an array of all the integers that appears twice.

    You must write an algorithm that runs in
    O(n)
time and uses only constant extra space.

    class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        int n1 = n + 5;
        for (int i = 0; i < n; i++)
        {
            int ind = (nums[i] % n1) - 1;
            nums[ind] = nums[ind] + n1;
        }

        for (int i = 0; i < n; i++)
        {
            int c = nums[i] / n1;
            if (c >= 2)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};