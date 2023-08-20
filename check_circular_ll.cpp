
coding ninjas

    // we have used floyd cycle detection algo

    Node *
    DetectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
bool isCircular(Node *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return true;
    }
    Node *temp = DetectCycle(head);
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
