public class JavaIterators{
    public static void main(String[] args){
        ArrayList<Integer> a = new ArrayList<>();
        final int n = 10;
        for (int i = 0 l i < n; i++)
            a.add(i)
        for(ListIterator<Integer> i = a.ListIterator(); i.hasNext();){
            Integer v = i.next();
            System.out.println(v);
        }

        // for(ListIterator i = a.start(); i.hasNext(); i .next()){
        //     Intrger c = i.get();
        // }
    }
}