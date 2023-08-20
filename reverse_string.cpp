

#include <bits/stdc++.h>
void reverse(string &str, int i, int j)
{
    if (i > j)
    {
        return;
    }
    // try to do with single pointer where j=n-i-1;
    swap(str[i], str[j]);
    i++;
    j--;
    reverse(str, i, j);
}
string reverseString(string str)
{
    // Write your code here.
    int i = 0;
    int j = str.length() - 1;
    reverse(str, i, j);

    return str;
}