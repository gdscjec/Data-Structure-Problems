class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.ans = []
        def backtrack(node , path):
            path.append(node)
            if node == len(graph) - 1: 
                self.ans.append(list(path))
            
            for neigh in graph[node]:
                backtrack(neigh,path)
            path.pop()
        backtrack(0,[])
        return self.ans
