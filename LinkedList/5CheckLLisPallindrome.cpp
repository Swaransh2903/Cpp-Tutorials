// Brute Approach : copy contents of list in an array and check for pallindrome in the newly created array.
// TC - O(N), SC - O(N)

// Optimized Approach: Find middle of ll, reverse the part after the middle, then compare the 2 halves (the normal 
// one before mid and reversed one after mid), if both are equal then pallindrome else not.
// TC- O(N),SC - O(1)

Node* getMid(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* reverse(Node* temp)
{
    Node* prev = NULL;
    Node* curr = temp;
    Node* next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node* head)
{
    // if the list contains 0 or 1 node then it's already pallindrome
    if(head == NULL || head->next == NULL)
        return true;
    
    // We'll be finding the middle element via hare and tortoise algo (slow & fast pointers).
    Node* middle = getMid(head);
    
    // we then reverse the list after the middle element and attach it to original list's middle->next.
    Node* temp = middle->next;
    middle->next = reverse(temp);

    //  then we compare both halves
    Node* start = head;
    Node* afterMiddle = middle->next;
    while(afterMiddle!=NULL)
    {
        if(afterMiddle->data!=start->data)
            return false;
        afterMiddle = afterMiddle->next;
        start = start->next;
    }

    // Before returning true restore original list
    temp = middle->next;
    middle->next = reverse(temp);

    return true;

}