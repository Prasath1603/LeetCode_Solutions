class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a , b) -> (b - a));

        for(int i : stones) pq.add(i);

        while(pq.size() >= 2){
            int a = pq.poll() , b = pq.poll();
            if(a == b) continue;
            else pq.add(Math.abs(a - b));
        }

        // while(!pq.isEmpty()){
        //     System.out.println(pq.poll());
        // }
        if(!pq.isEmpty()) return pq.poll();
        return 0;
    }
}