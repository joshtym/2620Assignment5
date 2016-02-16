//**************************************************************************
// CPSC2620
// Use this listTest.cc client program to test your List class before you
// test it with prob1.cc and LineEditor
// Written by Arie
// Nov. 7, 2013

// Your Makefile should look like:
//  CXX=/opt/centos/devtoolset-1.1/root/usr/bin/g++
//  CXXFLAGS=-Wall -g -std=c++11

//  all: listTest
//  listTest : listTest.o List.o
//	$(CXX) $(CXXFLAGS) -o $@ $^
//  %.o : %.cc
//	$(CXX) -c $(CXXFLAGS) $<

//  List.o : List.h
//  listTest.o : List.h
//  clean:
//	rm -rf *~ *.o

//  clean-all: clean
//	rm -rf listTest

//
// Your output should look like:
//   This list is empty!
//   hello
//   o
//   l
//   helo
//   heljo
//***************************************************************************


#include<iostream>
#include"List.h"
using namespace std;

// overloaded << operator to print a list
ostream& operator<<(ostream&, const List&);

int main()
{
   List l1; // create an empty list
   List::Iterator it = l1.end();
   l1.insert(it,'h');
   l1.insert(it,'e');
   l1.insert(it,'l');
   l1.insert(it,'l');
   l1.insert(it,'o');
   cout << l1 << endl;
   --it;
   cout << *it << endl;
   --it;
   cout << *it << endl;
   if(it != l1.end())
   {
      auto old = it;
      ++it;
      l1.erase(old);
   }
   cout << l1 << endl;
   l1.insert(it,'j');
   cout << l1 << endl;
   return 0;
}

ostream& operator<<(ostream& outs, const List& l)
{
   if(l.begin() == l.end())
      outs << "This list is empty!" << endl;
   else
      for(auto it = l.begin(); it != l.end(); ++it)
	 outs << *it;
   return outs;
}


