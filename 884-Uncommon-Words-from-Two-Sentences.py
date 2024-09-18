class Solution:
    def uncommonFromSentences(self, str1: str, str2: str) -> List[str]:
        dict1 = {}
        s1 = list(map(str,str1.split(" ")))
        s2 = list(map(str,str2.split(" ")))
        for i in s1:
            if i in dict1:
                dict1[i]+=1
            else:
                dict1[i]=1
        dict2 = {}
        for i in s2:
            if i in dict2:
                dict2[i]+=1
            else:
                dict2[i]=1
        result = []
        # print(dict1,dict2)
        for i in dict1:
            if dict1[i]==1 and i not in dict2:
                result.append(i)
        for i in dict2:
            if dict2[i]==1 and i not in dict1:
                result.append(i)
        return result