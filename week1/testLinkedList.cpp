/*
CH-231-A
a1_p3.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include "LinkedList.h"//we import the class from the header file
using namespace std;
int main(){
    List<int> a;
    a.addf(1);
    a.addl(2);
    //print first and last
    cout<< a.first() << " "<< a.last() << endl;
    a.addl(3);
    //we delete and print elements
    while(a.numb()>0){
        cout<< a.dfirst()<<" "<< a.numb()<<endl;
    }
    //add one more
    a.addf(4);
    cout<< a.dlast()<< endl;
    return 0;
}