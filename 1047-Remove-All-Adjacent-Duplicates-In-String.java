class Solution {
    public String removeDuplicates(String s) {
        Stack<Character>stack = new Stack<>();
        for(char i : s.toCharArray()){
            if(!stack.isEmpty()){
                if(stack.peek() == i){
                    stack.pop();
                }
                else{
                    stack.push(i);
                }
            }
            else{
                stack.push(i);
            }
        }
        StringBuilder result = new StringBuilder();
        while(!stack.isEmpty()){
            result.append(stack.pop());
        }
        return result.reverse().toString();
        
    }
}