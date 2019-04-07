template <typename T>
class LinkedList
{
private:
  class node
  {
  public:
    T val;
    node *next;
    node(T v, node *n) : val(v), next(n) {}
  } node *head;
  node *tail;

public:
  LinkedList() : head(nullptr), tail(nullptr) {}

  void addFirst(T val)
  {
    if (head == nullptr)
    {
      head = tail = new node(val, nullptr);
      return;
    }
    head = new node(val, head);
  }

  void addLast(T val)
  {
  }

  bool
  isEmpty()
  {
  }
};

template <typename T>
class GrowAttay
{
private:
  int len;
  int capacity;
  T *data;
  void grow()
  {
    T *old = data;
    data = new T[capacity * 2 + 1];
    for (int i = 0; i < len; i++)
    {
      data[i] = old[i];
    }
    capacity = capacity * 2 + 1;
    delete[] old;
  }

public:
  GrowArray() : len(0), capacity(0), data(nullptr) {}

  void addFirst(T val)
  {
  }

  void addLast(T val)
  {
    if (len >= capacity)
    {
      grow();
    }
    data[len++] = val;
  }

  void removeLast()
  {
  }

  void isEmpty()
  {
  }
};

class Stack
{
private:
  // LinkedList impl;// addFirst o(1) addLast o(n) removeFirst o(1) removeLast o(n)
  // GrowArray impl; // addFirst o(n) addLast o(1) removeFirst o(n) removeLast o(1)
public:
  void push(int v) { impl.addFirst(v); }
  int pop() { return impl.removeFirst(); }
  bool isEmpty() {}
  int size() const {}
};

class Queue
{
private:
  LinkedList impl; //has head and tail;
public:
  void enqueue(int v) { impl.addLast(v) }
  int dequeue() { impl.removeFirst(); }
  bool isEmpty() { return impl.isEmpty(); }
};

int main()
{
}