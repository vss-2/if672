class Solution:
    def dfs(arv, h, pai, p, no):
        if(p != None):
            pai[no.val] = p
        arv[no.val] = h
        #print('O pai de',no.val,'é',pai[no.val])
        if(no.left != None):
            Solution.dfs(arv, h+1, pai, no.val, no.left)
        if(no.right != None):
            Solution.dfs(arv, h+1, pai, no.val, no.right)
        return
    
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        arv = [None]*111
        pai = [None]*111
        h = 0
        pai[root.val] = None
        Solution.dfs(arv, h, pai, None, root)
        return (arv[x] == arv[y] and pai[x] != pai[y])
    
"""
[1,2,3,null,4]
2
3
"""
