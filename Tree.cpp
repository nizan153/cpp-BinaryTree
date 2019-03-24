#include <iostream>
#include "Tree.hpp"
using namespace ariel;
using namespace std;
Node::~Node(){ }

//constructor
Tree::Tree() : head(NULL), sizeOfTree(0) {}

Tree::Tree(int x) : head(new Node(x)), sizeOfTree(1) {}

//destructor
Tree::~Tree()
{
    deleteTree(head);
}

// Delete Tree
void Tree::deleteTree(Node *root) {
    if(root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Insert value to tree
void Tree::insert(int i) {
    // if tree is empty create new tree
    if (!head) {
        head = new Node(i);
        sizeOfTree++;
    }
    //if tree contains value - throw exeption
    else if(contains(i)) {
        throw std::invalid_argument(to_string(i) + " already exist");
    }
    // else call recursive insert method
    else {
        insert(head, i);
        sizeOfTree++;
    }
}

// recursive insert to tree
void Tree::insert(Node *root, int i) {
    // if value is smaller then root go left 
    if(i < root->data) {
        if(root->left) {
            insert(root->left, i);
        }
        else {
            root->left = new Node(i);
        }
    }
    // if value is larger then root go right
    else if(i > root->data) {
        if(root->right) {
            insert(root->right, i);
        }
        else {
            root->right = new Node(i);
        }
    }
}

// Remove value from tree
void Tree::remove(int i) {
    // if tree is empty - throw exeption
    if (!head) {
        throw std::runtime_error("Tree is empty");
    }
    // if tree doesn't contains value - throw exeption
    else if(!contains(i)){
        throw std::invalid_argument(to_string(i) + " not found");
    }
    // else call recursive remove method
    else {
        remove(head, i);
        sizeOfTree--;
    }
}

// recursive remove from tree. find minimum in right subtree, value in targeted node and delete duplicated from right subtree
// returns deleted node
// https://gist.github.com/mycodeschool/9465a188248b624afdbf
Node* Tree::remove(Node* &root, int i) {
    if(!root) {return root;}
    //find node to remove
    else if (i < root->data) { root->left = remove(root->left, i);}
    else if (i > root->data) { root->right = remove(root->right, i); }
    else {
        // Case 1: No Child
        // delete node
        if((!root->left) && (!root->right)) {
            delete root;
            root = NULL;
        }
        // Case 2: 1 Child
        else if(!root->left) {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(!root->right) {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: 2 Childs
        else {
            // find min node on right subtree
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        } 
    }
    return root;
}

// return node with min value in subtree - used for remove
Node* Tree::findMin(Node *root) {
    while(root->left) { root = root->left; }
    return root;
}

//return size of tree
int Tree::size() {
    return sizeOfTree;
}

// check if node exist in tree
bool Tree::contains(int i) {
    return (getNode(i));
}

// return the value of root
int Tree::root() {
    if (!head) {
        throw std::runtime_error("The tree is empty");
    }
    return head->data;
}

// print tree
void Tree::print() {
    printPreorder(head);
}

//preorder print
void Tree::printPreorder(Node *root) {
    if(root) {
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

//postorder print
void Tree::printPostorder(Node *root) {
    if(root) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << " ";
    }
}

//inorder print
void Tree::printInorder(Node *root) {
    if(root) {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

// return value of left child
int Tree::left(int i)
{
    if((!head)|| (!contains(i))) {
        throw std::invalid_argument(to_string(i) + " not found");
    }

    Node *temp = getNode(i);

    if(temp->data == i && temp->left){
        return temp->left->data;
    }
    else {
        throw std::runtime_error(to_string(i) + " doesn't have left child");
    }
}

// return value of parent
int Tree::parent(int i){
    if(!head) {
        throw std::runtime_error("The tree is empty");
    } 
    if(!contains(i)) {
        throw std::invalid_argument(to_string(i) + " not found");
    }
    if(getNode(i) == head){
        throw std::runtime_error(to_string(i) + " doesn't have parent");
    }

    Node *par = head;
    Node *cur = head;

    while (cur) {
        if(i < cur->data) {
            par = cur;
            cur = cur->left;
        }
        else if(i > cur->data){
            par = cur;
            cur = cur->right;
        }
        else {
            return par->data;
        }
    }
    
    return 0;
}

// return value of right child 
int Tree::right(int i){
    if((!head) || (!contains(i))) {
        throw std::invalid_argument(to_string(i) + " not found");
    }

    Node *temp = getNode(i);

    if(temp->data == i && temp->right){
        return temp->right->data;
    }
    else {
        throw std::runtime_error(to_string(i) + " doesn't have right child");
    }
}

// return the node of value i
Node *Tree::getNode(int i) {
    // if tree empty return null
    if(!head) { return NULL; }

    Node *temp = head;

    while(temp){
        // if value smaller then node move left
        if(i < temp->data) {
            temp = temp->left;
        }
        // if value bigger then node move right
        else if(i > temp->data){
            temp = temp->right;
        }
        // else value equal to node value and return node 
        else {
            return temp;
        }
    }
    return NULL;
}