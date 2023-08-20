

coding ninjas

    Node *
    uniqueSortedList(Node *head)
{
    // Write your code here.
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while ((temp->next != NULL) && temp != NULL)
    { // if next list item has also same data
        if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
        { // if next list item is unique
            temp = temp->next;
        }
    }
    return head;
}