/*
CH-231-A
a2_p6.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(){
    //open file
    ifstream in("data.txt");
    string inp, date, name, sur;
    map<string,string> a;
    //we go through the whole file
    while(!in.eof()){
        in>> name >> sur >> date;
        inp=name+" "+sur;//full name
        a[inp]=date;
    }
    //we can go through and print the thing
    //but not requested so i commented it out
    /*
    map<string,string>::iterator cur;
    cur=a.begin();
    while(cur!=a.end()){
        cout<< cur->first << " "<< cur->second<< endl;
        cur++;
    }
    */
    in.close();
    return 0;
}