# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, li: List[Optional[ListNode]]) -> Optional[ListNode]:
        # if len(li) == 0:
        #     return None
        st = ""
        for i in li:
            temp = i
            while(temp):
                st+= str(temp.val)+" "
                temp = temp.next
        if st == "":
            return None
        l = list(map(int,st.split()))
        l.sort()
        ans = ListNode()
        temp = ans
        n= len(l)
        for i in range(n):
            temp.val = l[i]
            if(i!=n-1):
                temp.next = ListNode()
                temp = temp.next
        return ans
        