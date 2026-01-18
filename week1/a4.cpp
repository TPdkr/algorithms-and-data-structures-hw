/*
CH-231-A
a1_p4.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    //a vector of strings
    vector<string> a;
    //we need some value to enter the loop
    string inp="BEG";
    int num=0;//number of elements
    while (inp!="END"){
        cin>>inp;
        if (inp!="END"){
            //we add the element if it's not the end
            a.push_back(inp);
            num++;//increment
        }
        
    }
    //i wanted to print the number of elelments
    cout<<"Number of elements: "<< num << endl;
    for (int i=0;i<num;i++){//we go through the vector and print
        cout<<a[i];//we use index
        if (i!=num-1){
            cout<<" ";
        } else{
            cout<<"\n";
        }
    }
    //we use an iterator
    vector<string>::iterator cur;
    cur=a.begin();
    while(cur != a.end()){
        cout << *cur;//we ooutput
        //here we check if we're in between elements
        if ((cur+1) != a.end()){
            cout<<",";
        }
        cur++;
    }
    cout<<"\n";
    return 0;
}