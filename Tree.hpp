#ifndef TREE_H
#define TREE_H

namespace ariel
{
    class Node
    {
        private:
            Node *parent;
            Node *left;
            Node *right;
            int data;

        public:
            Node();
            Node(int x);
            ~Node();
            
    };

    class Tree
    {
        private: 
            Node *head;
            int s;

        public:

            Tree();
            Tree(int);
            ~Tree();

            void insert(int);
            void remove(int);
            int size();
            bool contains(int);
            int root();
            void print();
            int left(int);
            int parent(int);
            int right(int);
    };
}

#endif // TREE_H