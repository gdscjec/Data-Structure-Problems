import collections

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
       res, n = [], len(nums)
        nums.sort()
        for a in range(n):
            for b in range(a+1, n):
                c = b+1; d = n-1
                while c<d:
                    sums = nums[a]+nums[b]+nums[c]+nums[d]
                    if sums < target:
                        c += 1
                    elif sums > target:
                        d -= 1
                    else:
                        toappend = [nums[a],nums[b],nums[c],nums[d]]
                        if toappend not in res:
                            res.append(toappend)
                        c +=1
                        d-=1
        return res
