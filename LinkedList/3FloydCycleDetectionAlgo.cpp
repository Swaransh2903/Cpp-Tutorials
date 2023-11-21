// Normal Method to Detect Loops in Cycles: Map ka use krlo , TC - O(n), SC - O(n) -> Node* type ki key lelo jo ki
// pointers honge next node ke n values true/false hongi jo ki visited konse pointers h uss hisaab se change hongi.
// agr koi visited pointer pe fir phunch gye mtlb cycle h

// Optimized approach:



Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;
    

    // we use the tortoise and hare approach by defining slow & fast pointers and since the fast pointer moves
    // 2x times the slow pointer , there will be a point where both the pointers will meet(if cycle is present)
    // else fast becomes NULL(if there is no cycle)
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {

        // because our while condn already checks for fast==NULL, we can safely move fast by 1. 
        fast = fast -> next;

        // however there could be a scenario wherein fast was pointing to the last node, so fats->next==NULL,so if
        // we would've directly moved fast by 2 then it would've meant fast->next->next which would result in
        // segmentation fault because(NULL->next).
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;
        
        // if slow and fast meet, cycle exists,so we return the intersection point
        if(slow == fast) {
            return slow;
        }
    }
    
    // if we get out of the loop that means fast became NULL and so no cycle, hence we return NULL.
    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    // first we get the intersection point
    Node* intersection = floydDetectLoop(head);
    
    // if intersection point was NULL,that means the list didn't contain any cycle,so we simply return NULL
    if(intersection == NULL)
        return NULL;
    
    // else our list did contain a loop & hence we determine the starting point of loop:
    // Note: Look for the proof of this algo online
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  
    
    // returning the starting point
    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    // we call the fnc to get the starting point
    Node* startOfLoop = getStartingNode(head);
    
    // if the fnc returned NULL , that means there was no cycle, hence no loop needs to be removed so we simply
    // return the original head
    if(startOfLoop == NULL)
        return head;
    
    // else if we got the starting point, we know that we'll have to reach that node whose next would point to
    // the starting point of cycle and we would've to make it point to NULL instead.
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;

    // after removal of loop,return the original head.
    return head;
}