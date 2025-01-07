class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        t = ' '.join(words)
        return [i for i in words if t.count(i) > 1]
        