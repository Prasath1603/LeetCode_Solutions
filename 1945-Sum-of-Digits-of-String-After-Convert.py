class Solution:
    def getLucky(self, s: str, k: int) -> int:
        # Creating a dictionary with letters as keys and numbers as values
        d = {chr(i): i - 96 for i in range(97, 123)}
        x=""
        for i in s:
            x+=str(d[i])
        x=int(x)
        n=len(str(x))
        while k>0:
            sum=0
            for i in range(n):
                sum+=(x%10)
                x//=10
            x=sum
            n=len(str(x))
            k-=1
        return x