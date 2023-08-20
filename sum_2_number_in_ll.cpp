
GFG

    class Solution
{
public:
    // Function to add two numbers represented by linked list.
    struct Node *reverse(struct Node *head)
    {
        struct Node *prev = NULL;
        struct Node *curr = head;
        struct Node *forward = head;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void insertattail(struct Node *tail1, struct Node *temp)
    {
        tail1->next = temp;
        tail1 = temp;
    }

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        struct Node *head1 = new Node(0);
        struct Node *tail1 = new Node(0);
        head1->next = tail1;
        struct Node *first1 = reverse(first);
        struct Node *second1 = reverse(second);
        int carry = 0;
        while (first1 != NULL && second1 != NULL)
        {
            int num = first1->data + second1->data + carry;
            int digit = num % 10;
            carry = num / 10;
            struct Node *temp = new Node(digit);
            //  insertattail(tail1,temp);
            tail1->next = temp;
            tail1 = temp;
            first1 = first1->next;
            second1 = second1->next;
        }
        while (first1 != NULL)
        {
            int num = first1->data + carry;
            int digit = num % 10;
            carry = num / 10;
            struct Node *temp = new Node(digit);
            //  insertattail(tail1,temp);
            tail1->next = temp;
            tail1 = temp;
            first1 = first1->next;
        }

        while (second1 != NULL)
        {
            int num = second1->data + carry;
            int digit = num % 10;
            carry = num / 10;
            struct Node *temp = new Node(digit);
            //     insertattail(tail1,temp);
            tail1->next = temp;
            tail1 = temp;
            second1 = second1->next;
        }

        while (carry != 0)
        {
            struct Node *temp = new Node(carry);
            // insertattail(tail1,temp);
            tail1->next = temp;
            tail1 = temp;
            carry = carry / 10;
        }
        return reverse(head1->next->next);
    }
};
