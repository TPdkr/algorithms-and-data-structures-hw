/*
CH-231-A
a1_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include "Stack.h"
using namespace std;
int main(){
    //we create a stack of ints
    Stack<int> a;
    int b;
    //we add numbers
    for (int i=0;i<11;i++){
        cout<< a.push(i)<< endl;
    }
    Stack<int> c(a);
    Stack<int> d(2);//we use the other constructor
    d.push(8);
    d.pop(b);
    //we print the number of elements
    cout<< a.getNumEntries() << endl;
    //we print the last element and pop it
    for(int i=0;i<11;i++){
        cout<< a.back() << " "<< a.pop(b) << " " << b << endl;
    }
    cout << endl;
    //we check the copied stack
    for(int i=0;i<11;i++){
        cout<< c.back() << " "<< c.pop(b) << " " << b << endl;
    }
    return 0;
}