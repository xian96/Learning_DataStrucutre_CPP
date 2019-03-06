import java.util.*;

public class IntArrayList{
    private int [] data ;
    private int size;
    private final void checkGrow(){
        if (size >= data.length){
            int[] old = data;
            data = new int[2*data.length+1];
            System.arraycopy(old,0,data ,0,size);
        }
    }
    public static class Iterator{
        private IntArrayList list;
        private int pos;

        public Iterator(IntArrayList list){
            this.list = list;
            pos =0;
        }

        public boolean hasNext(){
            return pos < list.size;
        }
        public void next(){
            pos++;
        }
        public int value(){
            return list.data[pos];
        }
    }
    public IntArrayList(int capaciy){
        data = new int[capacity];
        size =0;
    }
    public void addEnd (int v){
        checkGrow();
        data[size++] = v;
    }
    public static void testIntArray(int n){
        IntArrayList a = new IntArrayList(n);
        for(int i = 0; i<n; i++)
            a.addEnd(i);
    }
    public stati void testArrayList(int n){
        IntArrayList<Integer> a = new IntArrayList<>(n);
        for(int i = 0; i<n; i++)
            a.add(i);
    }
    public static void main(String[] args){
        long t0 = System.nanoTime();
        testIntArray(n);
        // testArrayList(n)
        long t0 = System.nanoTime();
        System.out.println((t1-t0)*1e-9)

        final int N2 = 10;
        IntArray a = new IntArray();
        for(int  i = 0; i<N2;i++)
            a.addEnd(i);

        int sum = 0;
        for(Iterator i = a.begin; i.hasNext(); i.next())
            sum += i.value();
   }
}