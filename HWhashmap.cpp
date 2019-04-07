// author:jiaxian xing
// HashMapLinearChaining
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <fstream>

using namespace std;

int hashCode(string word)
{
    hash<string> string_hash;
    return string_hash(word);
}

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
        tail = new node(val, nullptr, tail);
        tail->prev->next = tail;
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
        node *i = head;
        if (head == tail)
        {
            head = tail = nullptr;
            delete i;
            return;
        }
        for (; i->next->next != nullptr; i = i->next)
            ;
        tail = i;
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
            if (i == nullptr) //means out of range;
                return;
            i = i->next;
            pos--;
        }
        i->next = new node(val, i->next, i);
    }

    int size()
    {
        if (head == nullptr)
            return 0;
        node *i = head;
        int sum;
        for (; i->next != tail; i = i->next)
            sum++;
        return sum;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    bool find(T val)
    {
        if (isEmpty())
            return false;
        bool flag = false;
        for (node *p = head; p->next != nullptr; p = p->next)
        {
            if (p->val == val)
                flag = true;
        }
        return flag;
    }

    class iterator
    {
    private:
        linkedlist3<T> &linkedlist;
        node *p;

    public:
        iterator(linkedlist3<T> &list) : linkedlist(list), p(linkedlist.head) {}
        // iterator(node * p): p(p){}
        void operator++()
        {
            p = p->next;
        }

        bool operator!()
        {
            // cout<<"test test "<<(p != nullptr);
            return p != nullptr;
        }

        T const &operator*()
        {
            return p->val;
        }
    };
};
class HashMap
{
private:
    linkedlist3<string> *hashTable[20];

public:
    HashMap()
    {
        for (int i = 0; i < 20; i++)
        {
            hashTable[i] = nullptr;
        }
    }
    int hashFunction(string word)
    {
        int key = hashCode(word) % 20;
        return abs(key);
    }
    void insert(string word)
    {
        int key = hashFunction(word);
        if (hashTable[key] == nullptr)
        {
            hashTable[key] = new linkedlist3<string>;
        }
        hashTable[key]->addEnd(word);
    }
    bool haveWord(string word)
    {
        int key = hashFunction(word);
        return hashTable[key]->find(word);
    }
    void histogram()
    {
        for(int i = 0; i< 20; i++)
        {
            cout << "hashTable " << i << "\t" << hashTable[i]->size()<<endl;
        }
    }
};

int main()
{
    HashMap hm;
    string line;
    ifstream file("dict.txt");
    if (file)
    {
        cout << "open the dict.txt SUCCESSFUL" << endl;
        while (getline(file, line))
        {
            hm.insert(line);
        }
    }
    else
        cout << "FALL open the dict.txt" << endl;
    file.close();
    file = ifstream("hw8.dat");
    if (file)
    {
        cout << "open the hw8.dat SUCCESSFUL" << endl;
        while (getline(file, line))
        {
            if (hm.haveWord(line))
            cout << line << ": TRUE" << endl;
            else cout << line << ": FALSE" << endl;
        }
    }
    else
        cout << "FALL open the hw8.dat" << endl;
    file.close();
    hm.histogram();
}
