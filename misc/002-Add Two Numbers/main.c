#define NULL 0

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addNode(struct ListNode* l1, struct ListNode* l2, int* carry);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // Base case
    // If L1 is empty, then L2 is either also empty, or contains solution.
    if(l1 == NULL)
        return l2;
    // If L2 is empty then L1 contains the solution.
    if(l2 == NULL)
        return l1;

    struct ListNode* l3, *w;
    int carry = 0;

    // Create return list head
    l3 = addNode(l1, l2, &carry);

    // Walk L1 and L2 to next values
    if(l1 != NULL)
        l1 = l1->next;
    
    if(l2 != NULL)
        l2 = l2->next;

    w = l3;
    while((l1 != NULL) || (l2 != NULL))
    {
        w->next = addNode(l1, l2, &carry);

        // Walk all three node lists
        w = w->next;

        if(l1 != NULL)
            l1 = l1->next;
    
        if(l2 != NULL)
            l2 = l2->next;
    }

    // Append straggling carried values
    if(carry)
    {
        w->next = malloc(sizeof(struct ListNode));
        w->next->val = carry;
        w->next->next = NULL;
    }

    return l3;

}

struct ListNode* addNode(struct ListNode* l1, struct ListNode* l2, int* carry)
{
    int v1, v2, vTotal, vRemainder;
    struct ListNode* rNode;

    // Initialize working data
    v1 = v2 = 0;
    if(l1 != NULL)
        v1 = l1->val;
    if(l2 != NULL)
        v2 = l2->val;

    // Calculate node values
    vTotal = v1 + v2 + *carry;
    vRemainder = vTotal % 10;
    *carry = vTotal / 10;

    // Instanticiate new node
    rNode = malloc(sizeof(struct ListNode));
    rNode->val = vRemainder;
    rNode->next = NULL;
    return rNode;
}