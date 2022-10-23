 class Solution:
2.     def maxPathSum(self, root: TreeNode) -> int:
3. 		max_path = float("-inf") 
4. 		def get_max_gain(node):
5. 			nonlocal max_path
6. 			if node is None:
7. 				return 0
8. 				
9. 			gain_on_left = max(get_max_gain(node.left), 0) 
10. 		gain_on_right = max(get_max_gain(node.right), 0) 
11. 			
12. 		current_max_path = node.val + gain_on_left + gain_on_right
13. 		max_path = max(max_path, current_max_path) 
14. 			
15. 		return node.val + max(gain_on_left, gain_on_right) 
16. 			
17. 			
18. 	get_max_gain(root) 
19. 	return max_path		
