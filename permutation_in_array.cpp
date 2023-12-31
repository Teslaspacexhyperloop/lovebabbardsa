
leetcode 46

    Given an array nums of distinct integers,
    return all the possible permutations.You can return the answer in any order.

           Example 1 :

    Input : nums = [ 1, 2, 3 ] Output : [ [ 1, 2, 3 ], [ 1, 3, 2 ], [ 2, 1, 3 ], [ 2, 3, 1 ], [ 3, 1, 2 ], [ 3, 2, 1 ] ]

                                        class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> nums, int ind)
    {
        if (ind >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(ans, nums, ind + 1);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};