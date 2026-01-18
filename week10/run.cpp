/*
CH-231-A
a10_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include<iostream>
#include "BST.h"
using namespace std;
int main(){
    //here i have an array i transfer into the tree for testing
    int data[]={2,50,23,10,60,-20, 13,24,44, 37};
    RedBlackTree a;//our test tree
    int n=10;
    for(int i=0;i<n;i++){
        a.insertRB(data[i]);//insertion test
    }
    a.printThorough();//here we can see that it's balanced
    a.print();//it tests that its bst
    //we can see the get miminum and maximum working
    cout<<"Minumum: "<< a.getMinimum()->data<< endl;
    cout<<"Maximum: "<< a.getMaximum()->data<< endl;
    //we test search for elements in the tree
    cout<<"Search for element: "<< a.search(50)->data<<endl;
    cout<<"Search for element: "<< a.search(51)->data<<endl;
    //tests of corner cases and regular cases for predecessor and succesor
    cout<< "Testing successor\n"<<a.successor(a.getMaximum())->data<< endl;
    cout<< "Testing successor\n"<<a.successor(a.search(50))->data<< endl;
    cout<< "Testing predecessor\n"<<a.predecessor(a.getMinimum())->data<< endl;
    cout<< "Testing predecessor\n"<<a.predecessor(a.search(50))->data<< endl;
    a.print();
    //we test the delete funtionality
    a.deleteRB(a.search(23));
    a.deleteRB(a.search(37));
    a.print();
    //we test it still being balanced and correct through printing
    a.printThorough();
    return 0;
}