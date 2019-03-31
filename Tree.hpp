#ifndef TREE_H
#define TREE_H
#include <iostream>

namespace ariel
{
    class Node{
        public:
            Node *left;
            Node *right;
            int data;
            Node(int i) : data(i), left(NULL), right(NULL) {}
    };

    class Tree
    {
        private:
            Node *head; 
            int sizeOfTree;

            void deleteTree(Node*);
            Node* getNode(int);
            void printPreorder(Node*);
            void printPostorder(Node*);
            void printInorder(Node*);
            void insert(Node*, int);
            Node* remove(Node*&, int);
            Node* findMin(Node*);
            

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