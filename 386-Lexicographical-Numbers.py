class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        return list(map(int,sorted([str(i+1) for i in range(n)])))
        