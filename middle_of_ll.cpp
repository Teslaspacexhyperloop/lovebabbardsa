coding ninjas

    Node *
    findMiddle(Node *head)
{
    // Write your code here
    /*
    int middle=getlength(head)/2;
    Node*temp=head;
    while(middle!=0){
        temp=temp->next;
        middle--;
    }
    return temp;*/
    Node *player2 = head;
    Node *player1 = head->next;
    if (head->next == NULL)
    {
        return head;
    }
    // when there are two node
    if (head->next->next == NULL)
    {
        return head->next;
    }
    while (player1 != NULL)
    {
        player1 = player1->next;
        if (player1 != NULL)
        {
            player1 = player1->next;
        }
        player2 = player2->next;
    }
    return player2;
}