

coding ninjas;

void insertatbottom(stack<int> &s, int element)
{

    if (s.empty())
    {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    // recursive call
    insertatbottom(s, element);
    s.push(num);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {

        return;
    }

    int num = stack.top();
    stack.pop();
    // recursive call
    reverseStack(stack);
    insertatbottom(stack, num);
}