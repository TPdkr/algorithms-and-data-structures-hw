/*
CH-231-A
a2_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <list>
#include <fstream>
using namespace std;
int main(){
    list<int> a,b;
    ofstream out("listB.txt");
    int inp=1;
    //input 
    while(inp>0){
        cin>>inp;
        if (inp>0){
            a.push_back(inp);
            b.push_front(inp);
        }
    }
    list<int>::iterator a1,b1;
    a1=a.begin();
    b1=b.begin();
    //I output the contents to standard output 
    while(a1!=a.end()){
        cout << *a1;
        a1++;
        if ((a1) != a.end()){
            cout<<" ";//check if between
        }
    }
    cout<< endl << endl;
    //we print the contents into a file
    while(b1!=b.end()){
        out << *b1;
        b1++;
        if ((b1) != b.end()){
            out<<" ";//check if between
        }
    }
    //we move the first elements to the back of the lists
    int ch=*a.begin();
    a.push_back(ch);
    a.pop_front();
    ch=*b.begin();
    b.push_back(ch);
    b.pop_front();
    //we print the lists in standard output using an interator
    a1=a.begin();
    b1=b.begin();
    while(a1!=a.end()){
        cout << *a1;
        a1++;
        if ((a1) != a.end()){
            cout<<",";//check if between
        }
    }
    //here we print list b
    //we merge list A and B
    cout<< endl;
    while(b1!=b.end()){
        cout << *b1;
        a.push_front(*b1);
        b1++;
        if ((b1) != b.end()){
            cout<<",";//check if between
        }
    }
    cout << endl<< endl;
    a.sort();
    a1=a.begin();
    while(a1!=a.end()){
        cout << *a1;
        a1++;
        if ((a1) != a.end()){
            cout<<" ";//check if between
        }
    }
    cout<< endl;
    out.close();
    return 0;
}