# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):

        # Default exit case
        # If L1 is empty, then L2 is either empty, or is the return value.
        if(l1 == None):
            return l2
        # If L2 is empty then L1 was not empty, and is the return value.
        if(l2 == None):
            return l1

        t1 = ListNode(val=0,next=l1)
        t2 = ListNode(val=0,next=l2)
        return self.addTwoNumbersRecurse(t1,t2,0)

    def addTwoNumbersRecurse(self, l1, l2, carry):

        # Base case
        if(l1.next is None and l2.next is None):
            return ListNode(val=carry) if carry is not 0 else None

        vL = 0 if l1.next is None else l1.next.val
        vR = 0 if l2.next is None else l2.next.val
        vTotal = vL + vR + carry
        vRemainder = vTotal % 10
        carry = vTotal // 10
        
        t1 = l1.next if l1.next is not None else l1
        t2 = l2.next if l2.next is not None else l2
        return ListNode(vRemainder,self.addTwoNumbersRecurse(t1, t2, carry))


if(__name__ == "__main__"):

    n1 = [9,9,9]
    n2 = [8,9,9,9,9,9]

    l1 = ListNode()
    w = l1
    for v in n1:
        w.next = ListNode(val=v)
        w = w.next

    l2 = ListNode()
    w = l2
    for v in n2:
        w.next = ListNode(val=v)
        w = w.next
    
    l1 = l1.next
    l2 = l2.next   

    w = Solution().addTwoNumbers(l1,l2)
    while(w is not None):
        print(w.val)
        w = w.next