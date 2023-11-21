

Node* kReverse(Node* head,int k)
{
    // base case
    if(head == NULL)
        return NULL;

    // Step 1: Reverse first K elements manually(i.e first group):
    int cnt=0;
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(cnt<k && curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Step 2 : next K-1 groups will be reversed via recursion:
    if(next!=NULL)
    {
        head->next = kReverse(next,k);
    }
    
    // return head of reversed List:
    return prev;  
}