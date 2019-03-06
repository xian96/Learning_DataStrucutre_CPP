// linked list with head  and taili & next pointer;
#include <iostream>
using namespace std;

template <typename T>
class linkedlist2
{
  private:
    class node
    {
      public:
        T val;
        node *next;
        node(T v, node *n) : val(v), next(n) {}
    };

    node *head;
    node *tail;
  public:

    linkedlist2() : head(nullptr), tail(nullptr) {}
    ~linkedlist2()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        //no need to delete the tail, that's only a pointer; delete node is good;
    }

    void addStart(T val)
    {
        if (head == nullptr)
        {
            head = tail = new node(val, nullptr);
            return;
        }
        head = new node(val, head);
    }

    void addEnd(T val)
    {
        if (head == nullptr)
        {
            head = tail = new node(val, nullptr);
            return;
        }
        node *i = head;
        if (i->next == nullptr || head == tail)
        {
            tail = head->next = new node(val, nullptr);
            return;
        }
        for (; i->next != nullptr; i = i->next)
            ;
        tail = i->next = new node(val, nullptr);
    }

    void removeStart()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            head = tail = nullptr;
            return;
        }
        head = head->next;
    }

    void removeEnd()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            head = tail = nullptr;
            return;
        }
        node *i = head;
        for (; i->next->next != nullptr; i = i->next)
            ;
        node *temp = i->next;
        temp = nullptr;
        delete temp;
    }
};

int main()
{
    linkedlist2<int> a;
    a.addStart(1);
    a.addEnd(2);
    a.removeEnd();
    a.removeEnd();
    a.removeStart();
}