

coding ninjas

#include <bits/stdc++.h>
    /****************************************************************
        Following is the Linked List node structure

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

    *****************************************************************/

    Node *
    kReverse(Node *head, int k)
{
    // step 1 reverse first k group
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // ste[p 2]==baaki recursion dekh lega
    if (next != NULL)
    {
        head->next = kReverse(next, k); // recursion givehead of remainingglist
    }
    // step 3 return prev as it is head
    // yha originally retuurn prev likha tha
    return prev;
    // Write your code here.
}