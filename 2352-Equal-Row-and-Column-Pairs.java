class Solution {
    public int equalPairs(int[][] grid) {
        HashMap<String,Integer> mp = new HashMap<>();
        int n = grid.length;
        for(int i = 0 ; i < n ; i++){
            String s = "";
            for(int j = 0 ; j < grid[0].length ; j++){
                char ch = (char) grid[j][i];
                s += String.valueOf(ch);
            }
            mp.put(s,mp.getOrDefault(s,0) + 1);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            String s = "";
            for(int j = 0 ; j < n ; j++){
                char ch = (char) grid[i][j];
                s += String.valueOf(ch);
            }
            if(mp.containsKey(s)){
                count += mp.get(s);
            }
        }
        return count;
    }
}