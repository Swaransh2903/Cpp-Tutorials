// 3->4->5 + 2->3   , Suppose we are adding these ll , then this is equivalent to adding numbers: 345 + 23 = 368
// but the main catch is when we add numbers, we do it backwards, however in singly LL we can only move in forward
// direction then how to perform the correct addition?

// Soln: What if we reverse both lists? i.e. 3->4->5 becomes 5->4->3 & similarly, 2->3 becomes 3->2. Then we can 
// perform the addtion from the front on the reversed lists and by reversing the final o/p obtained via addition,
// we can get the desired result.

// we pass by reference, so as the changes are made in the original list itself.
void insertAtTail(Node* &head, Node* &tail,int data)
{
    // create a new node with the data
    Node* temp = new Node(data);
    
    // if our list is empty currently, then both head and tail will point to the currently created node, which will
    // be the start node of the answer list.
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    // else if we had already created a node, we would attach the new node after the node already created &
    // update the tail pointer
    else
    {
        tail->next = temp;
        tail = temp;
    }
}


Node* add(Node* first,Node* second)
{
    // for the addition at any place, the sum will be the summation of the carry + both lists current data:
    // so we define a carry variable with initial value 0
    int carry = 0;

    // Now we have to create the list we'll be getting by addition, so we define the start and end pointers of the
    // list and assign NULL value for now.
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    // Now we specify the loop condition , basically the loop will run till either of the list gets exhausted. One
    // more condition: what if both the lists were of same length and the last addition resulted in a carry greater
    // than 0? Logically,we should've created a new node and placed the carry value there. However if we only 
    // do the NULL check for both the lists , then we won't be able to get the correct ans for this case and so
    // we also run the loop till carry becomes 0.
    while(first != NULL || second != NULL || carry != 0)
    {
        // Why initially val1 & val2 have been assigned 0 value? Because the lists could be of different lengths
        // and there can be case that when we are adding the list2 data to sum , list1 might have got exhausted
        // and vice versa and so we add 0 in that case.
        int val1 = 0;
        if(first != NULL)
            val1 = first->data;
        int val2 = 0;
        if(second != NULL)
            val2 = second->data;
        
        // calculate sum and create a new node with the sum's last digit value(rest becomes carry)
        int sum = carry + val1 + val2;
        int digit = sum % 10;

        // insert data at tail of the new list
        insertAtTail(ansHead,ansTail,digit);

        // get the carry for next summation
        carry = sum/10;

        // only move the pointers forward if that list has still not got exhausted.
        if(first != NULL)
            first = first -> next;
            
        if(second != NULL)
            second = second -> next;
    }
    
    // the head of the updated list will be at ansHead, so return it
    return ansHead;
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
Node* reverseTwoLists(Node* first,Node* second)
{
    // if any of the list is empty, then the result of addition would be the other list.
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    // first we reverse both the lists:
    first = reverse(first);
    second = reverse(second);

    // next we add the reversed lists:
    Node* ans = add(first,second);

    // next we reverse the resultant list:
    ans = reverse(ans);

    // optional step: before returning the final ans, we reverse our original lists again just to preserve their
    // original structure:
    first = reverse(first);
    second = reverse(second);
   
    // next we return the resultant list's head pointer.
    return ans;
}