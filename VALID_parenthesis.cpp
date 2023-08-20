coding ninjas;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    map<char, char> m;
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else if (m[ch] != s.top())
            {
                return false;
            }
            s.pop();
        }
    }
    if (s.empty())
        return true;
    else
    {
        return false;
    }
}