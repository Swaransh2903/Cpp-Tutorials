Node* reverseALinkedList(Node* head)
{
    if(head==NULL||head->next==NULL)
    return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward;
    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

    }
    return prev;
}

// Recursive Soln:

// Best Explanation: https://www.youtube.com/watch?v=S92RuTtt9EE
void reverse(Node* &head,Node* curr,Node* prev)
{
    // base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev; 
}