class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < operations.length; i++){
            String s = operations[i];
            switch(s){
                case \C\:
                    if(!stack.isEmpty()){
                        stack.pop();
                    }
                    break;
                case \D\:
                    if(!stack.isEmpty()){
                        stack.push(stack.peek() * 2);
                    }
                    break;
                case \+\:
                    if (stack.size() >= 2) {
                        int top1 = stack.pop(); 
                        int top2 = stack.peek();
                        stack.push(top1); 
                        stack.push(top1 + top2);
                    }
                    break;
                default:
                    stack.push(Integer.parseInt(s));
            }
        }
        int total = 0;
        for(int i:stack){
            total+=i;
        }
        return total;
    }
}