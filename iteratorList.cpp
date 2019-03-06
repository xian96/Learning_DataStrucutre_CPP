// template <typename T>
// class GrowArray
// {
//   private:
//     int capacity;
//     int len;
//     char *data;

//   public:
//   GrowArray(int capacity: capacity(capacity), len(0), data(new char[sizeof(T)*capacity])){}
//   ~GrowArray(){
//       for(int i = 0; i < len; i++){
//         //   call destructuor on only elements that exist!;
//       }
//   }
// }
template <typename T>
class GrowArray
{
  private:
    int capacity;
    int len;
    T *data;

  public:
    GrowArray(int capacity): capacity(capacity), len(0), data(new T[capacity])) {}
    ~GrowArray()
    {
        for (int i = 0; i < len; i++)
        {
            delete[] data;
        }
    }
    GrowArray(const GrowArray &orig) : capacity(orig.capacity), len(orig.len)
    {
        data = new T[capacity];
        for (int i = 0; i < len; i++)
            data[i] = orig.data[i];
    }
    void operator=(const GrowArray &orig) = delete;
    void addEnd(int v)
    {
        if (len <= capacity)
        {
            T *old = data;
            data = new T[capacity * 2];
            for (int i = 0; i < len; i++)
                data[i] = old[i];
            delete[] old;
        }
    }
    class iterator
    {
      private:
        GrowArray<T> &list;
        int pos;

      public:
        iterator(GrowArray<T> &list) : list(list), pos(0) {}
        bool operator!() const { return pos < list.len; }
        operator++() { pos++; }
        T &operator*() { return list.data[pos]; }
    };
};

int main()
{
    GrowArray<int> a(3);
    a.addEnd(5);
    a.addEnd(5);
    GrowArray<int> b = a;
    for (GrowArray<int>::iterator i = a; !il i++)
        cout << *i;
}