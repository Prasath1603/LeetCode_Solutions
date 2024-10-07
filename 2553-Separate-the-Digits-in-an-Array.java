class Solution {
    public int[] separateDigits(int[] nums) {
        List<Character> l = new ArrayList<>();
        for(int i = 0 ; i < nums.length; i++){
            String s = String.valueOf(nums[i]);
            for(int j = 0; j < s.length() ; j++){
                l.add(s.charAt(j));
            }
        }
        int arr[] = new int[l.size()],j = 0;
        for(char i : l){
            arr[j++] = i - '0';
        }
        return arr;
    }
}