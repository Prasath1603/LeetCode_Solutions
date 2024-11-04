class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        l=list(s)
        g=list(goal)
        for i in range(len(l)):
            if l==g:
                return True
            else:
                x=l.pop(0)
                l.append(x)
        return False
        