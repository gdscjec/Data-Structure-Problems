
def largestNumber1(self, nums):
    if not any(nums):
        return "0"
    return "".join(sorted(map(str, nums), cmp=lambda n1, n2: -1 if n1+n2>n2+n1 else (1 if n1+n2<n2+n1 else 0)))
    

def largestNumber2(self, nums):
    for i in xrange(len(nums), 0, -1):
        for j in xrange(i-1):
            if not self.compare(nums[j], nums[j+1]):
                nums[j], nums[j+1] = nums[j+1], nums[j]
    return str(int("".join(map(str, nums))))
    
def compare(self, n1, n2):
    return str(n1) + str(n2) > str(n2) + str(n1)
    

def largestNumber3(self, nums):
    for i in xrange(len(nums), 0, -1):
        tmp = 0
        for j in xrange(i):
            if not self.compare(nums[j], nums[tmp]):
                tmp = j
        nums[tmp], nums[i-1] = nums[i-1], nums[tmp]
    return str(int("".join(map(str, nums))))
    

def largestNumber4(self, nums):
    for i in xrange(len(nums)):
        pos, cur = i, nums[i]
        while pos > 0 and not self.compare(nums[pos-1], cur):
            nums[pos] = nums[pos-1]  # move one-step forward
            pos -= 1
        nums[pos] = cur
    return str(int("".join(map(str, nums))))

        
def largestNumber5(self, nums):
    nums = self.mergeSort(nums, 0, len(nums)-1)
    return str(int("".join(map(str, nums))))
    
def mergeSort(self, nums, l, r):
    if l > r:
        return 
    if l == r:
        return [nums[l]]
    mid = l + (r-l)//2
    left = self.mergeSort(nums, l, mid)
    right = self.mergeSort(nums, mid+1, r)
    return self.merge(left, right)
    
def merge(self, l1, l2):
    res, i, j = [], 0, 0
    while i < len(l1) and j < len(l2):
        if not self.compare(l1[i], l2[j]):
            res.append(l2[j])
            j += 1
        else:
            res.append(l1[i])
            i += 1
    res.extend(l1[i:] or l2[j:])
    return res
    

def largestNumber(self, nums):
    self.quickSort(nums, 0, len(nums)-1)
    return str(int("".join(map(str, nums)))) 

def quickSort(self, nums, l, r):
    if l >= r:
        return 
    pos = self.partition(nums, l, r)
    self.quickSort(nums, l, pos-1)
    self.quickSort(nums, pos+1, r)
    
def partition(self, nums, l, r):
    low = l
    while l < r:
        if self.compare(nums[l], nums[r]):
            nums[l], nums[low] = nums[low], nums[l]
            low += 1
        l += 1
    nums[low], nums[r] = nums[r], nums[low]
    return low
