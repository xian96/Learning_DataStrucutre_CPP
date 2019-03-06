// linked list with only head & next pointer;
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class linkedList1
{
  private:
    class node
    {
      public:
        T val;
        node *next;
        node(T val, node *n) : val(val), next(n) {}
    };

    node *head;
  public:
    linkedList1() : head(nullptr) {}
    ~linkedList1()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addStart(T val)
    {
        head = new node(val, head);
    }

    void addEnd(T val)
    {
        node *i = head;
        if (head == nullptr) //exception handel;
        {
            head = new node(val, nullptr);
            return;
        }
        for (; i->next != nullptr; i = i->next)
            ;
        i->next = new node(val, nullptr);
    }

    void removeStart()
    {
        if (head == nullptr)
        {
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    void removeEnd()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            node *temp = head;
            delete temp;
            head = nullptr;
            return;
        }
        node *i;
        for (i = head; i->next->next != nullptr; i = i->next)
            ;
        node *temp = i->next;
        i->next = nullptr;

        delete temp;
    }

    void insert(T val, int pos)
    {
        if (head == nullptr)
            return;
        node *i = head;
        while (pos > 0)
        {
            if (i->next == nullptr)
                return;
            i = i->next;
            pos--;
        }
        i->next = new node(val, i->next);
    }
};

int main()
{
    linkedList1<int> a;
    a.removeStart();
    a.addEnd(2);
    a.removeEnd();
    a.addStart(1);
    a.insert(2, 1);
    // cout << " test test";
}