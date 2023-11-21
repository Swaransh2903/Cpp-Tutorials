//  What's given in the question? Normally, in a single LL, you generally have a node which contains a data field
// and a pointer to the next node. However in this question we'll be given a random pointer(for every node) in 
// addition to the data field and next pointer and this pointer can point to any node in the LL (it can even point
// to itself and to NULL). We have to create a 'deep copy' of this LL. Now what is a deep copy? In a deep copy,
// we'll be creating an exact same copy of the LL with all the next as well as random pointers, however these nodes
// will be created at a different place in the memory. i.e If the address of node containing 1 had next pointer 555
//  & it was pointing to node containing 2, in the new list also 1 would point to 2 , however the next pointer address
// would be changed because these nodes are getting created at some other place in memory. So there could be a 
// scenario that a particular node's random pointer is pointing to some node that has still not been created, so 
// how do we deal with this problem? This we'll be seeing in this soln:

// One method to solve this with extra space: What we can do is we can map addresses of original list's nodes with
// the new list's corresponding nodes addresses. So that if a->random points to b , then m[a]->random will point to
// m[b].

Node* copyRandomList(Node* head)
{
    // address to address mapping
    map<Node*,Node*> mp;
    Node* temp = head;

    // Note: if we are creating mapping we don't need to explicitly connect the nodes of the cloned list in the
    // while loop. Assume that 5 new Node* type blocks were assigned with random pointers, however since all of them
    // have been mapped w.r.t to original list, we can connect them later by using these mappings.
    while(temp != NULL)
    {
        Node* copy = new Node(temp->data);
        mp[temp] = copy;
        temp = temp->next;
    }
    temp = head;

    // making connections:
    while(temp != NULL)
    {
        // connecting next pointers:
        mp[temp]->next = mp[temp->next];

        // connecting random pointers:
        mp[temp]->random = mp[temp->random];
        
        temp = temp->next;
    }
    return mp[head];
}


// no extra space:
// Refer to this explanation : https://www.youtube.com/watch?v=uBjpRedaNKQ


void copyList(Node* head)
{
    Node* temp = head,*n = head->next;
    while(temp != NULL)
    {
        Node* copy = new Node(temp->data);
        temp->next = copy;
        copy->next = n;
        temp = n;
        if(n!=NULL)
        n = n->next;
    }
}
void handleRandom(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->random != NULL)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
}
Node* detach(Node* head)
{
    Node* dummy = new Node(-1);
    Node* tail = dummy,*temp = head;
    while(temp != NULL)
    {
        tail->next = temp->next;
        tail = tail->next;
        temp->next = tail->next;
        temp = temp->next;
    }
    return dummy->next;
}
Node* copyRandomList(Node* head){
    if(head == NULL)
        return NULL;
    copyList(head);
    handleRandom(head);
    return detach(head);
}