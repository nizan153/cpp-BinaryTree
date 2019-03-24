/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree1;
  ariel::Tree mytree2;
  ariel::Tree mytree3;  

  mytree1.insert(25);
  mytree1.insert(50);
  mytree1.insert(35);
  mytree1.insert(15);
  mytree1.insert(10);
  mytree1.insert(4);
  mytree1.insert(22);
  mytree1.insert(70);
  mytree1.insert(12);
  mytree1.insert(66);
  mytree1.insert(90);
  mytree1.insert(31);
  mytree1.insert(44);
  mytree1.insert(24);
  mytree1.insert(18);

  
  mytree2.insert(15);
  mytree2.insert(11);
  mytree2.insert(8);
  mytree2.insert(4);
  mytree2.insert(1);
  mytree2.insert(0);

  mytree3.insert(10);
  mytree3.insert(6);
  mytree3.insert(25);
  mytree3.insert(15);
  mytree3.insert(23);
  mytree3.insert(28);
  mytree3.insert(34);
  mytree3.insert(37);
  mytree3.insert(32);
  mytree3.insert(33);
  mytree3.insert(9);

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  
  // my tests
  .CHECK_EQUAL(mytree1.size(), 15)
  .CHECK_EQUAL(mytree1.root(), 25)
  .CHECK_EQUAL(mytree1.left(22), 18)
  .CHECK_EQUAL(mytree1.right(50), 70)
  .CHECK_OK(mytree1.insert(0))
  .CHECK_OK(mytree1.remove(35))
  .CHECK_EQUAL(mytree1.parent(90), 70)
  .CHECK_EQUAL(mytree1.size(), 15)
  .CHECK_THROWS(mytree1.remove(77))
  .CHECK_THROWS(mytree1.left(90))
  .CHECK_THROWS(mytree1.insert(25))
  .CHECK_THROWS(mytree1.parent(25))
  .CHECK_OK(mytree1.print())


  .CHECK_EQUAL(mytree2.size(), 6)
  .CHECK_EQUAL(mytree2.root(), 15)
  .CHECK_EQUAL(mytree2.left(11), 8)
  .CHECK_EQUAL(mytree2.contains(1), true)
  .CHECK_OK(mytree2.insert(20))
  .CHECK_OK(mytree2.remove(15))
  .CHECK_THROWS(mytree2.insert(20))
  .CHECK_THROWS(mytree2.right(4))
  .CHECK_THROWS(mytree2.remove(2))
  .CHECK_OK(mytree2.print())


  .CHECK_EQUAL(mytree3.size(), 11)
  .CHECK_EQUAL(mytree3.right(6), 9)
  .CHECK_EQUAL(mytree3.left(34), 32)
  .CHECK_EQUAL(mytree3.parent(33),32)
  .CHECK_OK(mytree3.insert(2))
  .CHECK_OK(mytree3.remove(23))
  .CHECK_OK(mytree3.insert(0))
  .CHECK_EQUAL(mytree3.size(), 12)
  .CHECK_EQUAL(mytree3.parent(0), 2)
  .CHECK_THROWS(mytree3.right(0))
  .CHECK_THROWS(mytree3.remove(1))
  .CHECK_THROWS(mytree3.remove(66))
  .CHECK_THROWS(mytree3.insert(6))
  .CHECK_THROWS(mytree3.parent(10))
  .CHECK_OK(mytree3.print())
  ;
 
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
