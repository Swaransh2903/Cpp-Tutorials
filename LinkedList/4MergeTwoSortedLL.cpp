void solve(Node<int>* first, Node<int>* second) {
    
    // if only one element is present in the first list:
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }
    // defining the pointers required:
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    
    // for our first list we have a next pointer and the curr2 pointer for second list, so we keep a track that none
    // of them end up getting NULL.
    while(next1 != NULL && curr2 != NULL) {
        
        // if the second list node's data lies b/w the 2 adjacent node's data of the first list, then update 
        // the pointers
        if( (curr2 -> data >= curr1 -> data ) 
           && ( curr2 -> data <= next1 -> data)) {
            
            curr1 -> next = curr2;
            next2 = curr2->next;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        // if the second list node's data dosen't lie in b/w, that means it is greater than both curr1 & next1 
        // data and so move both the pointers by 1. 
        else {
            curr1 = next1;
            next1 = next1 -> next;
            // if while shifting the pointer the next1 pointer becomes NULL,that means we've reached the end of list
            // and there are no more elements left for comparison , so we simply attach the remaining part of the second
            // list after the first list.
            if(next1 == NULL)
            {
                curr1->next1 = curr2;
                return first;
            }
            
        }
        
        
    }
    
    
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // if anyone of the list contains 0 elements, then return the head of the other list.
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    // The logic we are using is that we are seeing that if a node of one list can be placed b/w 2 adjacent nodes
    // of the other list based on their data. If yes then we modify the pointers accordingly, else we only 
    // increment the pointers of the list for which we are considering the adjacent element to point to the next 2
    // for comparison and see if the element can be inserted in b/w or not.

    // Basically our solve func will create the curr & next pointers for the first argument and the second arguments
    // curr will be compared,thus we have to pass the pointer will smaller data as first argument.
    if(first -> data <= second -> data ){
        solve(first, second);
    }
    else
    {
        solve(second, first);
    }
    
    
}