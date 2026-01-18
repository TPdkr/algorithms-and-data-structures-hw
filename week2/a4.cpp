/*
CH-231-A
a2_p4.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    for(int i=1;i<31;i++){
        a.push_back(i);
    }
    //we add 5
    a.push_back(5);
    //we use the reverse funtion
    reverse(a.begin(), a.end());
    //here we output using an iterator
    vector<int>::iterator cr;
    cr=a.begin();
    while(cr!=a.end()){
        cout<< *cr;
        cr++;
        //I don't want to print spaces in between
        if (cr!=a.end()){
            cout<<" ";
        }
    }
    cout<< endl << endl;
    //we replace using a replace funciton
    replace(a.begin(), a.end(), 5, 129);
    //here we output using an iterator
    cr=a.begin();
    while(cr!=a.end()){
        cout<< *cr;
        cr++;
        //I don't want to print spaces in between
        if (cr!=a.end()){
            cout<<" ";
        }
    }
    cout<< endl;
    return 0;
}