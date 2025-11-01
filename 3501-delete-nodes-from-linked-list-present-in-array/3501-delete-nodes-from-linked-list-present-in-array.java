/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> set = new HashSet<>();
        for(int i : nums){
            set.add(i);
        }
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        while(head != null){
            int x = head.val;
            if(!set.contains(x)){
                // System.out.println(x + " " + set.contains(x));
                temp.next = head;
                temp = temp.next;
            }
            head = head.next;
        }
        temp.next = null;
        return (dummy.next != null) ? dummy.next : null;
    }
}