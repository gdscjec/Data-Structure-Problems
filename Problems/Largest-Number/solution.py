class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        for i,n in enumerate(nums):
            nums[i]=str(n)
        def comparison(n,m):
            if n+m>m+n:
                return -1
            else:
                return 1
        nums=sorted(nums, key=cmp_to_key(comparison))
        return str(int("".join(nums)))
