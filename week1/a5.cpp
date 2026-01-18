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
    //a vector for strings
    vector<string> a;
    string inp="BEG";//need to enter the loop
    char buf[200];//a buffer C string
    int num=0;
    while (inp!="END"){
        //we need the whole line with spaces which is why we can't use cin
        //but getline uses C string so I needed that
        cin.getline(buf,200);
        inp=string(buf);
        if (inp!="END"){
            //add element
            a.push_back(inp);
            num++;
        }
        
    }
    //we swap if we can
    if (num>=5){
        string swap;
        swap=a[4];
        a[4]=a[1];
        a[1]=swap;
    } else{
        cout<<"Less than 5 elements. Can't swap\n";
    }
    //replace the last with ???
    if(num>=1){
        a[num-1]="???";
    }
    //I wanted to print the number of elements
    cout<<"Number of elements: "<< num << endl;
    //we print using index
    for (int i=0;i<num;i++){
        cout<<a[i];
        //check if inbetween
        if (i!=num-1){
            cout<<",";
        } else{
            cout<<"\n";
        }
    }//we use the itereator to print
    vector<string>::iterator cur;
    cur=a.begin();
    while(cur != a.end()){
        cout << *cur;
        if ((cur+1) != a.end()){
            cout<<";";//check if between
        }
        cur++;
    }
    cout<<"\n";
    cur=a.end();
    //we print backwards the string vector
    while(cur != a.begin()){
        cur--;
        cout << *cur;
        //here we check if we're in between
        if ((cur) != a.begin()){
            cout<<" ";
        }
    }
    cout<<"\n";
    return 0;
}