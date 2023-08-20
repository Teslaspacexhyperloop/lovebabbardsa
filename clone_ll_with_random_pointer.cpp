
GFG

    class Solution
{
public:
    Node *copyList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        map<Node *, Node *> m;

        Node *head1 = new Node(0);
        Node *tail = new Node(0);

        head1->next = tail;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *clone = new Node(temp->data);
            tail->next = clone;
            tail = clone;
            temp = temp->next;
        }
        temp = head;
        Node *temp1 = head1->next->next;
        while (temp != NULL)
        {
            m[temp] = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp1 = head1->next->next;
        temp = head;
        while (temp1 != NULL)
        {
            temp1->arb = m[temp->arb];
            temp = temp->next;
            temp1 = temp1->next;
        }

        return head1->next->next;
    }
