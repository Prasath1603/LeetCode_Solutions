class Solution {
    public boolean lemonadeChange(int[] bs) {
        int a=0,b=0,c=0,i;
        for(i=0;i<bs.length;i++){
            if(bs[i]==5)
            a++;
            else if(bs[i]==10){
                if(a==0)
                return false;
                else
                {
                    a--;
                    b++;
                }
            }
            else if(bs[i]==20){
                if(a>0 && b>0){
                    a--;
                    b--;
                }
                else if(a>2){
                    a-=3;
                }
                else
                return false;
            }
        }
        return true;
    }
}