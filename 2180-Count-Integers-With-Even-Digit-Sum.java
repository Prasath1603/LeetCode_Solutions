class Solution {
    public int countEven(int num) {
        int count = 0;
        for(int i = 1; i < num + 1 ; i++){
            int x = i,sum = 0;
            while(x > 0){
                sum += x % 10;
                x /= 10;
            }
            if(sum % 2 == 0) count++;
        }
        return count;
    }
}