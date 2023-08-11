leetcode 1047

    You are given a string s consisting of lowercase English letters.A duplicate removal consists of choosing two adjacent and equal letters and removing them.

    We repeatedly make duplicate removals on s until we no longer can.

    Return the final string after all such duplicate removals have been made.It can be proven that the answer is unique.

    Example 1 :

    Input : s = "abbaca" Output : "ca" Explanation : For example,
            in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

                                                                                                                                                                                                                class Solution
{
public:
    string removeDuplicates(string s)
    {
        string str = "";
        stack<char> st;
        int n = s.length();
        if (n <= 1)
        {
            return s;
        }
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (!st.empty() && s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            str = str + st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
