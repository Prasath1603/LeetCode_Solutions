from typing import List

class Solution:
    def findMinDifference(self, t: List[str]) -> int:
        time_in_minutes = []
        for time in t:
            hours = int(time[:2])  
            minutes = int(time[3:]) 
            t = hours * 60 + minutes
            time_in_minutes.append(t)
        
        time_in_minutes.sort()
        min_diff = float('inf')
        n = len(time_in_minutes)
        for i in range(n - 1):
            min_diff = min(min_diff, time_in_minutes[i + 1] - time_in_minutes[i])
        min_diff = min(min_diff, (1440 - time_in_minutes[-1] + time_in_minutes[0]))
        return min_diff
