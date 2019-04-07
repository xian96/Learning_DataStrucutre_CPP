class RBTrss
{
  private:
    class Node
    {
      public:
        enum Color{RED,BLACK};
        int val;
        Node *left;
        Node *right;
        Node *parent;
        Node(int v, Node *l, Node *r, Node *p) : val(v), left(l), right(r), parent(p), c(RED) {}
    };
    Node *root;

  public:
    RBTree() : root(nullptr) {}

    void add(int v)
    {
        Node *p = root;
        if (p == null)
        {
            root = new Node(v, nullptr, nullptr, nullptr);
        }
        else
        {
            do
            {
                if (v > p->val)
                {
                    if (p->r == nullptr)
                    {
                        p->r = new Node(v, null, null, p);
                        insertFixUpTree(p->right);
                        return;
                    }
                    else
                    {
                        p = p->r;
                    }
                }
                else
                {
                    if (p->l == nullptr)
                    {
                        p->l = new Node(v, nullptr, nullptr, p);
                        insertFixUpTree(p->left);
                        return;
                    }
                    else
                    {
                        p = p->l;
                    }
                }
            } while (p != nullptr)
        }
    }

    void insertFixUpTree(Node * n)
    {
        
    }
}