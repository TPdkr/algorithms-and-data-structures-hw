/*
CH-231-A
a2_p5.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(NULL));
    int num;
    //I used a set as it makes sure no element is repeated
    set<int> a;
    //we add the elements
    while (a.size()<6){
        num =rand()%49+1;//we use rand
        a.insert(num);
        //cout << num << endl;
    }
    //we use an iterator
    set<int>::iterator it;
    it=a.begin();
    while(it!=a.end()){
        //output
        cout << *it << " ";
        it++;
    }
    cout<< endl;
    return 0;
}