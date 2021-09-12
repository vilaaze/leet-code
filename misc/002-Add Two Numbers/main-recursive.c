#define NULL 0

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbersRecurse(struct ListNode* l1, struct ListNode* l2, int carry);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // Base case
    // If L1 is empty, then L2 is either also empty, or contains solution.
    if(l1 == NULL)
        return l2;
    // If L2 is empty then L1 contains the solution.
    if(l2 == NULL)
        return l1;

    struct ListNode *n1, *n2;

    n1 = malloc(sizeof(struct ListNode));
    n2 = malloc(sizeof(struct ListNode));
    n1->next = l1;
    n2->next = l2;

    return addTwoNumbersRecurse(l1, l2, 0);

}

struct ListNode* addTwoNumbersRecurse(struct ListNode* l1, struct ListNode* l2, int carry)
{
    int v1, v2, vTotal, vRemainder;
    struct ListNode* rNode;

    if((l1->next == NULL) && (l2->next == NULL))
    {
        if(carry)
        {
            rNode = malloc(sizeof(struct ListNode));
            rNode->val = carry;
            rNode->next = NULL;
        }
        else
        {
            return NULL;
        }
    }

    // Initialize working data
    v1 = v2 = 0;
    if(l1->next != NULL)
    {
        v1 = l1->next->val;
        l1 = l1->next;
    }

    if(l2->next != NULL)
    {
        v2 = l2->next->val;
        l2 = l2->next;
    }

    // Calculate node values
    vTotal = v1 + v2 + carry;
    vRemainder = vTotal % 10;
    carry = vTotal / 10;

    // Instanticiate new node
    rNode = malloc(sizeof(struct ListNode));
    rNode->val = vRemainder;
    rNode->next = addTwoNumbersRecurse(l1, l2, carry);
    return rNode;
}