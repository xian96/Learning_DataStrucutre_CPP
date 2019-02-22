template<typename T>
class linkedlist{
    class Node{//linkedlist
        public:
         int val;
         Node* next;

         Node(int v, Node n):val(v), next(n){}
    };
    
    Node* head;

public: linkedlist(){
        head = nullptr;//O(1)
    }
    void addsStart(int v){
        Node* temp = new Node();
        temp->val = v;
        temp->next = head;// remember this
        head = temp;
    }
    void addEnd(int v){
        Node* temp = new Node();
        temp->val =v;
        temp->next = nullptr;
        Node p;
        if (head == nullptr){
            head == temp;
            return;
        }
        //invariant: head is not nullptr, list has tat least 1 element
        for(p = head; p->next != nullptr; p= p->next)
            ;
        //invariant : p is pointing to the last element;
        p->next = temp;
    }
    void insert(int pos, int v){
        Node p =head;
        while(pos > 0){
            p = p->next;
            pos--;
        }
        Node temp = new Node();
        temp->val = v;
        temp->next = p->next;
        p->next = temp;
    }
    int removeStart(){
        Node temp = head;
        head = head->next;
        return temp->val;
    }
    int removeEnd(){
        Node p = head;
        Node q = p->next;
        if(q == nullptr){
            int temp = head->val;
            head = nullptr;
            return temp;
        }
        for (; q->next != nullptr; p = p->next, q = q->next)
        ;
        p->next = nullptr;
        return p->val;
    }

    String toString(){
        StringBuilder b = new StringBuilder();
        for(Node p = head ; p != nullptr; p = p->next)
            b->apped(p->val)->append(' ');
        return b->toString();
    }
};
int main (){
        linkedlist<int> a;
        a.addsStart(1);
        a.addsEnd(1);

}

