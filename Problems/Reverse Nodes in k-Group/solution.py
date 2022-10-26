# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        temp = head
        arr = [[]]
        i,j = 0,0
        
        while temp:
            arr[i].append(temp.val)
            j+=1
            temp = temp.next
            if j==k:
                arr.append([])
                j=0
                i+=1
                
        for i in arr:
            if len(i) == k:
                i.reverse()
                
        temp = head
        pre = temp
        n = len(arr)
        
        for i in range(n):
            for j in arr[i]:
                temp.val = j        
                temp.next = ListNode()
                pre = temp
                temp = temp.next
                
        pre.next = None
        return head
        