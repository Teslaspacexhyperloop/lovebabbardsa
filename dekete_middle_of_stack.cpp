
coding ninjas

#include <bits/stdc++.h>
    void
    solve(stack<int> &inputStack, int count, int size)
{
    // basr case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }
    int keepaside = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, size);
    inputStack.push(keepaside);
}
void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}