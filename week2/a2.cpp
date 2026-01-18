/*
CH-231-A
a2_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<float> a;
    float inp=1;
    int num=0;
    //input 
    while(inp!=0){
        cin>>inp;
        if (inp>0){
            a.push_back(inp);
            num++;
        } else if (inp<0){
            a.push_front(inp);
            num++;
        }
    }
    deque<float>::iterator a1;
    a1=a.begin();
    //I output the contents to standard output 
    while(a1!=a.end()){
        cout << *a1;
        a1++;
        if ((a1) != a.end()){
            cout<<" ";//check if between
        }
    }
    cout<< endl << endl;
    //we search for the fisrt positive
    a1=a.begin();
    while((a1!=a.end())&&(*a1<0)){
        a1++;
        if(*a1>0){
            //we insert
            a.insert(a1, 0);
            break;
        }
    }
    //in case there are no positive elements
    if (a.back()<0){
        a.push_back(0);
    }
    //in case there are no negative elements
    if (a.front()>0){
        a.push_front(0);
    }
    a1=a.begin();
    //I output the contents to standard output 
    while(a1!=a.end()){
        cout << *a1;
        a1++;
        if ((a1) != a.end()){
            cout<<";";//check if between
        }
    }
    cout<< endl;
    return 0;
}