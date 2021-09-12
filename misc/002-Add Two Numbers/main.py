# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        # Default exit case
        # If L1 is empty, then L2 is either empty, or is the return value.
        if(l1 == None):
            return l2
        # If L2 is empty then L1 was not empty, and is the return value.
        if(l2 == None):
            return l1

        # Create the head node for the return list
        l3, carry = self.addNode(l1,l2,0)
        n3 = l3
        l1 = l1.next if l1 is not None else None
        l2 = l2.next if l2 is not None else None

        while((l1 is not None) or (l2 is not None)):
            n3.next, carry = self.addNode(l1,l2,carry)

            # Step linked lists to next elems
            n3 = n3.next
            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None
        
        # Append carried value if applicable
        if carry is not 0:
            n3.next = ListNode(val=(carry), next=None)

        return l3

    def addNode(self, l1: Optional[ListNode], l2: Optional[ListNode], carry: Optional[int]=0) -> tuple[ListNode,int]:
        vL = 0 if l1 is None else l1.val
        vR = 0 if l2 is None else l2.val
        vTotal = vL + vR + carry
        vRemainder = vTotal % 10

        return(ListNode(val=vRemainder, next=None), vTotal//10)
