
coding ninjas;

#include <bits/stdc++.h>
void sortedinsert(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();

    stack.pop();
    // recursive call
    sortedinsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);

    sortedinsert(stack, num);
}