#include <iostream>
#include "Tree.hpp"

using namespace ariel;
using namespace std;

int main(){

// try{
//     Tree t; 
//     t.insert(5);
//     // t.insert(2);
//     // t.insert(8);
//     // t.insert(3);
//     // t.insert(1);
//     // t.insert(0);
//     // t.insert(-1);
//     // t.insert(-2);
//     cout <<"countain 5? " << t.contains(0) << " size: " << t.size() << endl;
//     t.remove(0);
//     cout << "countain 5? " << t.contains(0) << " size: " << t.size() << endl;
//     // cout << "contaitns: true: " << t.contains(0) << " false: " << t.contains(43) << endl;
//     // cout << "Size: " << t.size() << endl;
//     // cout << "Root: " << t.root() << endl;
//     // cout << "parent: " << t.parent(-2) << endl;
//     // cout << "left: " << t.left(-1) << endl;
//     // cout << "right: " << t.right(2) << endl;
//     // cout << "before remove: ";
//     // t.print();
//     // cout << endl << "after remove: ";
//     // // t.remove(5);
//     // t.remove(8);
//     // t.print();
//     // cout << endl << "Size: " << t.size() << endl;

// }
// catch(const std::exception& ex) {
//     cout << ex.what()<< endl;
// }

Tree emptytree;

cout << emptytree.size() << endl;
emptytree.insert(5);
emptytree.print();
cout << emptytree.size() << endl;
cout << emptytree.contains(5) << endl;
emptytree.remove(5);
cout << emptytree.contains(5) << endl;
emptytree.print();


    return 0;
}