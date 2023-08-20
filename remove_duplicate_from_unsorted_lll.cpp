

coding ninjas

    Node *
    removeDuplicates(Node *head)
{
    // Write your code here
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    Node *prev = NULL;
    map<int, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp->data] == false)
        {
            visited[temp->data] = true;
            prev = temp;
        }
        else
        {
            prev->next = temp->next;
        }

        temp = temp->next;
    }
    return head;
}