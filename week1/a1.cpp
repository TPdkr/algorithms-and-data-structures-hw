/*
CH-231-A
a1_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <complex>
using namespace std;
//here's our template declaration 
template <class T>
//here we define the funtion using the template 
int array_search(T a[],int n, T goal){
    for(int i=0;i<n;i++){
        if(a[i]==goal){
            return i;
        }
    }
    //return -1 of nothing is found
    return -1;
}

int main(){
    //arrays of int, float and char that we can search
    int a[]={1,2,3,4,5};
    float b[]={1.3, 123, -9.0, 4.5 , 2.3};
    char c[]={'a', 'b', 'c', 'd', 'e'};
    //here we have a complex class array
    complex<float> d[]={1,2,4,4,5};
    //search function call and output
    cout<< array_search<int>(a,5,6) << endl;
    cout<< array_search<float>(b,5,1.3) << endl;
    cout<< array_search<char>(c,5,'e') << endl;
    complex<float> w;
    w=5;
    //we search the array of complex
    cout<< array_search<complex<float>>(d,5, w) << endl;
    return 0;
}