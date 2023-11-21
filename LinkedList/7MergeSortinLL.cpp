
//  merge the lists by using the logic for merging 2 sorted lists
Node* merge(Node* left,Node* right)
{
    // if any one of the lists is empty, the other list will be the answer
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    
    // Let's merge by a new method:

    // we create a dummy node first with -1 value. Why? In this approach we'll be comparing the left half's current 
    // node data with the right half's current node data and whichever is smaller, we'll place first. So basically
    // this dummy node with a random value will act as the starting pointer for the merged list before any 
    // comparison, so that the smaller value node can act as the next to this dummy node. Similarly we'll be
    // updating this next pointer at every step.At last we'll be returning the ans->next because our list should
    // start with the smallest value after merging and not the dummy node.
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL)
    {
        if(left->data <= right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next; 
        }

    }

    // if anyone of the list got exhausted due to unequal length, then we copy the remaining part of either list
    // as it is
    while(left!=NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
     
    // At last we'll be returning the ans->next because our list should
    // start with the smallest value after merging and not the dummy node.
    ans = ans->next;
    return ans;

}

// find middle element via tortoise and hare algo
Node* getMid(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* mergeSort(Node *head)
{
    // if there is 0 or 1 element in list, then it's already sorted
    if(head == NULL || head->next == NULL)
        return head;

    // just like merge sort in case of arrays, we divide the LL in 2 halves from middle:
    Node* middle = getMid(head);

    // our first half will start from the head node itself
    Node* left = head;

    // the second  half starts after middle element
    Node* right = middle->next;

    middle->next = NULL;
    
    // recursively sort the halves (i.e we break the list till it's possible and then we combine the lists in sorted
    // order)
    left = mergeSort(left);
    right = mergeSort(right);

    // merge left & right halves in sorted order
    // In each case we'll be merging 2 lists, so we can apply the logic we used to merge 2 sorted lists.
    Node* result = merge(left,right);

}