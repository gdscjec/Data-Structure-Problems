class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return
        arr=[]
        while head:
            arr.append(head.val)
            head=head.next
        arr.sort()
        dummy=curr=ListNode(0)
        for i in arr:
            temp=ListNode(i)
            curr.next=temp
            curr=curr.next
        return dummy.next
