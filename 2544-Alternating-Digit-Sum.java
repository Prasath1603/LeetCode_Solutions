class Solution {
    public int alternateDigitSum(int n) {
        int sum = 0,flag = 0 , i = 0;
        String s = String.valueOf(n);
        // String r = new StringBuilder(s).reverse().toString();
        while( i < s.length()){
            int x = s.charAt(i) - '0';
            // System.out.println(x + " " + flag);
            if(flag == 0){
                sum += x;
                flag = 1;
            }
            else if(flag == 1){
                sum += (-(x));
                flag = 0;
            }
            i++;
        }
        return sum;
    }
}