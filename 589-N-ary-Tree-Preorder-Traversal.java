/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void dfs(Node root,List l){
        if(root==null){
            return ;
        }
        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while(!stack.isEmpty()){
            Node currentNode = stack.pop();
            l.add(currentNode.val);

            List<Node> children = currentNode.children;
            for(int i=children.size()-1;i>=0;i--){
                stack.push(children.get(i));
            }
        }
    }
    public List<Integer> preorder(Node root) {
        List<Integer> l = new ArrayList<>();
        dfs(root,l);
        return l;
    }
}