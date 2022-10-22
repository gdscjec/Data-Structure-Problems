lass Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.max_sum = float('-inf')
        self.dfs(root)
        return self.max_sum
    
    def dfs(self, node):
        if not node: return 0
        
        # only add positive contributions
        leftST_sum = max(0, self.dfs(node.left))
        rightST_sum = max(0, self.dfs(node.right))

        # check if cumulative sum at current node > global max sum so far
        # this evaluates a candidate path
        self.max_sum = max(self.max_sum, leftST_sum + rightST_sum + node.val)
        
        # add to the current node ONLY one of the children contributions
        # in order to maintain the constraint of considering only paths
        # if not, we would be exploring explore the whole tree - against problem definition
        return max(leftST_sum, rightST_sum) + node.val
