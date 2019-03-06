// linked list with head and taili & next and prev pointer;
#include <istream>
using namespace std;

template <typename T>
class linkedlist3
{
  private:
    class node
    {
      private:
      public:
        T val;
        node *next;
        node *prev;
        node(T v, node *n, node *p) : val(v), next(n), prev(p) {}
    }; 
    node *head;
    node *tail;

  public:
    linkedlist3() : head(nullptr), tail(nullptr) {}
    ~linkedlist3()
    {
    }

    void addStart(T val)
    {
        if (head == nullptr)
        {
            head = tail = new node(val, nullptr, nullptr);
            return;
        }
        head = new node(val, head, nullptr);
        head->next->prev = head;
        // tail = head->next;//no need to change!
    }

    void addEnd(T val)
    {
        if (head == nullptr)
        {
            head = tail = new node(val, nullptr, nullptr);
            return;
        }
        tail = tail->next = new node(val, nullptr, tail);
    }

    void removeStart()
    {
        if (head == nullptr)
            return;
        node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
            delete temp;
            return;
        }
        head = head->next;
        //head->prev = nullptr;//is not need when delete temp;
        delete temp;
    }

    void removeEnd()
    {
        if (head == nullptr)
            return;
        node* i = head;
        if(head == tail)
        {
            head = tail = nullptr;
            delete i;
            return;
        }
        for(;i->next->next != nullptr; i = i->next)
            ;
        tail = i;
        node* temp = i->next;
        i->next = nullptr;
        delete temp;
    }

    void insert(T val, int pos)
    {
        if(head == nullptr) return;
        node* i = head;
        while(pos > 0)
        {
            if(i == nullptr)//means out of range;
                return;
            i = i->next;
            pos--;
        }
        i->next = new node(val,i->next,i);
    }
};

int main()
{
    linkedlist3<double> a;
    a.addEnd(1.1);
    a.addStart(1.2);
    a.insert(1.5,1);
    a.removeEnd();
    a.removeStart();
    a.removeEnd();

}