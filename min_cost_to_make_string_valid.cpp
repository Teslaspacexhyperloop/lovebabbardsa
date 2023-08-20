
coding ninjas;

#include <bits/stdc++.h>
void unbalance(stack<char> &st, string str)
{

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{' || s.empty())
        {
            s.push(ch);
        }
        else
        {
            if (s.top() == '{')
            {
                s.pop();
            }

            else
            {
                s.push(ch);
            }
        }
    }
}
int findMinimumCost(string str)
{
    stack<char> st;
    unbalance(st, str);
    int a = 0;
    int b = 0;
    while (!st.empty())
    {
        if (s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    return ((a + 1) / 2) + ((b + 1) / 2);
}