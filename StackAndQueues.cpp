class Stack
{
  private:
    // LinkedList impl;// addFirst o(1) addLast o(n) removeFirst o(1) removeLast o(n)
    GrowArray impl; // addFirst o(n) addLast o(1) removeFirst o(n) removeLast o(1)
  public:
    void push(int v) { impl.addFirst(v); }
    int pop() { return impl.removeFirst(); }
    bool isEmpty() {}
    int size() const {}
}

class Queue
{
  private:
    LinkedList2 impl; //has head and tail;
  public:
    void enqueue(int v) { impl.addLast(v) }
    int dequeue() { impl.removeFirst(); }
    bool isEmpty() { return impl.isEmpty(); }
}