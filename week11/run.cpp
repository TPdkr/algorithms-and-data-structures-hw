/*
CH-231-A
a11_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include "HashTable.h"
#include <iostream>
using namespace std;
int main(){
    //constructor call
    HashTable table=HashTable(10);
    //our values and keys
    int keys[]={1,2,3,4,5,6,7,8,9};
    int values[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    //inserting elements
    cout<<"Inserting the elements:\n";
    for (int i=0;i<n;i++){
        cout << values[i]<< " ";
        table.insertNode(keys[i], values[i]);
    }
    cout <<endl;
    //getting elements
    cout<<"getting the elements:\n";
    for (int i=0;i<n;i++){
        cout<< table.get(keys[i])<< " ";
    }
    cout << endl;
    cout<<"Trying get element that is not there:\n"<<table.get(10)<<endl;
    return 0;
}