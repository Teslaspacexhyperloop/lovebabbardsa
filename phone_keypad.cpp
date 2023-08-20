leetcode 17

    Given a string containing digits from 2 -
    9 inclusive,
    return all possible letter combinations that the number could represent.Return the answer in any order.

           A mapping of digits to
           letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.

           Example 1 :

    Input : digits = "23" Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

                                   class Solution
{
public:
    void solve(vector<string> & output, string ans, string & digits, int ind, int n, vector<string> &map)
    {
        if (ind >= digits.length())
        {
            output.push_back(ans);
            return;
        }

        int num = digits[ind] - '0';
        for (int i = 0; i < map[num].length(); i++)
        {
            ans.push_back(map[num][i]);
            solve(output, ans, digits, ind + 1, n, map);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        string ans;
        if (digits.length() == 0)
        {
            return output;
        }
        solve(output, ans, digits, 0, digits.length() - 1, map);
        return output;
    }
};