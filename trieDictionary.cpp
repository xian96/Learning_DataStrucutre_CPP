// author: Jiaxian Xing
// HW trie dictionary
// Notice: readin filename is "dict.txt" showed in main(); path should be current dir;
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class trie
{
  private:
    class node
    {
      public:
        node *next[26];
        bool isword;
        node()
        {
            isword = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
        }
    };
    node *root;
    void deleteNode(node *pnode)
    {
        for (int i = 0; i < 26; i++)
            if (pnode->next[i] != nullptr)
                deleteNode(pnode->next[i]);
        delete pnode;
    }

  public:
    trie()
    {
        root = new node;
    }
    ~trie()
    {
        for (int i = 0; i < 26; i++)
            if (root->next[i] != nullptr)
                deleteNode(root->next[i]);
        delete root;
    }
    void insert(string word)
    {
        node *pnode = root;
        //        cout << " test insert "<< word;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (pnode->next[index] == nullptr)
                pnode->next[index] = new node;
            pnode = pnode->next[index];
        }
        pnode->isword = true;
    }

    bool findword(string word)
    {
        node *pnode = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (pnode->next[index] != 0)
                pnode = pnode->next[index];
        }
        return pnode->isword;
    }

    bool findprefix(string prefix)
    {
        node *pnode = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (pnode->next[index] != 0)
                pnode = pnode->next[index];
            else
                return false;
        }
        return true;
    }

    void readDictionary(string fileName)
    {
        string line;
        ifstream file(fileName);
        if (file)
        {
            while (getline(file, line))
            {
                this->insert(line);
            }
        }
    }
};

int main()
{
    trie dict;
    dict.readDictionary("dict.txt");
    string line;
    ifstream myfile("hw5.txt");
    if (myfile)
    {
        while (getline(myfile, line))
        {
            if(dict.findword(line)) cout << line << " is word" << "\n & ";
            else cout << line << " is not a word" << "\n & ";
            
            if(dict.findprefix(line)) cout << line << " is prefix;" << "\n";
            else cout << line << " is not a prefix;" << "\n";
         }
    }
}