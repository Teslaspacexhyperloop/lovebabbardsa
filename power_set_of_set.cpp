

leetcode 78

    class Solution
{
private:
public:
    void powerset(vector<int> &nums, vector<vector<int>> &output,
                  vector<int> ans, int ind)
    {
        if (ind < 0)
        {
            output.push_back(ans);
            return;
        }
        // exclude
        powerset(nums, output, ans, ind - 1);

        // include
        ans.push_back(nums[ind]);
        powerset(nums, output, ans, ind - 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> output;
        vector<int> ans;
        powerset(nums, output, ans, nums.size() - 1);
        return output;
    }
};