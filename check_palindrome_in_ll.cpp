
GFG check palindrome

    struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
* /

    class Solution
{
public:
    // Function to check whether the list is palindrome.
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = head;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if (head == NULL)
        {
            return true;
        }

        // count no of node
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        int count1 = (count + 1) / 2;
        while (count1 != 0)
        {
            count1--;
            temp = temp->next;
        }

        Node *head1 = reverse(temp);

        while (head1 != NULL)
        {
            if (head->data != head1->data)
            {
                return false;
            }
            head = head->next;
            head1 = head1->next;
        }

        return true;
    }
};
