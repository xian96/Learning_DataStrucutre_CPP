public class linkedlist{
    private static class Node{//linkedlist
        public int val;
        public Node next;
    }

    private Node head;
    public linkedlist(){
        head = null;//O(1)
    }
    public void addsStart(int v){
        Node temp = new Node();
        temp.val = v;
        temp.next = head;// remember this
        head = temp;
    }
    public void addEnd(int v){
        Node temp = new Node();
        temp.val =v;
        temp.next = null;
        Node p;
        if (head == null){
            head == temp;
            return;
        }
        //invariant: head is not null, list has tat least 1 element
        for(p = head; p.next != null; p= p.next)
            ;
        //invariant : p is pointing to the last element;
        p.next = temp;
    }
    public void insert(int pos, int v){
        Node p =head;
        while(pos > 0){
            p = p.next;
            pos--;
        }
        Node temp = new Node();
        temp.val = v;
        temp.next = p.next;
        p.next = temp;
    }
    public int removeStart(){
        Node temp = head;
        head = head.next;
        return temp.val;
    }
    public int removeEnd(){
        Node p = head;
        Node q = p.next;
        if(q == null){
            int temp = head.val;
            head = null;
            return temp;
        }
        for (; q.next != null; p = p.next, q = q.next)
        ;
        p.next = null;
        return p.val;
    }

    public String toString(){
        StringBuilder b = new StringBuilder();
        for(Node p = head ; p != null; p = p.next)
            b.apped(p.val).append(' ');
        return b.toString();
    }
    public static void main (String[] args){
        linkedlist a = new linkedlist();

    }
}

