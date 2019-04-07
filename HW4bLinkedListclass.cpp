/*
author: jaixian xing
*/
// linked list with head  and taili & next pointer;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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


public:
    node *head;
    node *tail;
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

    class iterator
    {
    private:
        linkedlist2<T> &linkedlist;
        node *p;

    public:
        iterator(linkedlist2<T> &list) : linkedlist(list), p(linkedlist.head) {}
        // iterator(node * p): p(p){}
        void operator ++()
        {
            p = p->next;
        }

        bool operator !()
        {
            // cout<<"test test "<<(p != nullptr);
            return p != nullptr;
        }

        T const &operator*()
        {
            return p->val;
        }



    };

    // iterator begin()
    // {
    //     return iterator(head);
    // }
};

int main()
{
    linkedlist2<int> llt;
    ifstream file("HW4b.txt");
    string lineinput;
    string command[5] = {"ADD_FRONT", "ADD_BACK", "REMOVE_FRONT", "REMOVE_BACK", ""};
    while (getline(file, lineinput))
    {
        std::istringstream iss(lineinput);
        string a, b;
        iss >> a >> b;
        cout << "\n" << a << " " << b;

        if (a == "ADD_FRONT")
        {
            stringstream input_stringstream(b);
            string x, y, z;
            string delimiter = ":";
            x = b.substr(0, b.find(delimiter));
            b.erase(0, b.find(delimiter) + delimiter.length());
            y = b.substr(0, b.find(delimiter));
            b.erase(0, b.find(delimiter) + delimiter.length());
            z = b.substr(0, b.find(delimiter));
            b.erase(0, b.find(delimiter) + delimiter.length());


            for (int i = stoi(x); i <= stoi(z); i += stoi(y))
                llt.addStart(i);
        }
        else if (a == "ADD_BACK")
        {
            stringstream input_stringstream(b);
            string x, y, z;
            string delimiter = ":";
            x = b.substr(0, b.find(delimiter));
            b.erase(0, b.find(delimiter) + delimiter.length());
            y = b.substr(0, b.find(delimiter));
            b.erase(0, b.find(delimiter) + delimiter.length());
            z = b.substr(0, b.find(delimiter));
            b.erase(0, b.find(delimiter) + delimiter.length());

            for (int i = stoi(x); i <= stoi(z); i += stoi(y))
                llt.addEnd(i);
        }
        else if (a == "REMOVE_FRONT")
        {
            for (int i = 0; i < stoi(b); i++)
                llt.removeStart();
        }
        else if (a == "REMOVE_BACK")
        {
            for (int i = 0; i < stoi(b); i++)
                llt.removeEnd();
        }
        else
        {
            cout<<"\n";
            for (linkedlist2<int>::iterator i(llt); !i; ++i)
                cout << *i << ",";
        }
    }
}
