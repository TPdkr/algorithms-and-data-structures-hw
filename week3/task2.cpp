/*
CH-231-A
a3_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
//this is a fintion to print an array
void prnt(int* array, int len){
    for (int i=0; i<len; i++){
        cout<<array[i] << " ";
    }
    cout << endl;
}
/*as an invariant we have that all the elements up to i(included) are sorted
this function checks that condition and returns the result
*/
int loopInvariant(int* array, int len){
    for (int i=0;i<len-1;i++){
        if(array[i]>array[i+1]){
            return 0;
        }
    }
    return 1;
}
/*this funtion has some extra steps in order to show how the algorithm works
it takes in an array of integers and sorts them while printing the result of
 each step*/
void selectSortShow(int* array, int len){
    int count=0;//a counter to see how many times to we go through the loop
    cout<< "Before: \n";
    prnt(array, len);
    cout << endl;
    for(int i=0; i<len-1;i++){
        int min=array[i+1];//we need to compare the array to smth
        int pl= i+1;//we set the value of the next as a min
        for(int j=i+2;j<len;j++){//we search for the minimum value
            count++;
            if(array[j]<min){
                min=array[j];
                pl=j;//we save the place as well
            }
        }
        if(min<array[i]){
            array[pl]=array[i];
            array[i]=min;//swap
        }
        cout << i << ": ";
        prnt(array, len);
        cout << "Invariant: "<< loopInvariant(array,i) << endl;
    }
    cout<< "After: \n";
    prnt(array, len);
    cout<< "Counter: " << count<< endl;
}
/*This is a cleaner implementaion that only sorts the values*/
void selectSort(int* array, int len){
    for(int i=0; i<len-1;i++){
        int min=array[i+1];//we need to compare the array to smth
        int pl= i+1;//we set the value of the next as a min
        for(int j=i+2;j<len;j++){//we search for the minimum value
            if(array[j]<min){
                min=array[j];
                pl=j;//we save the place as well
            }
        }
        if(min<array[i]){
            array[pl]=array[i];
            array[i]=min;//swap
        }
    }
}
/*this funtion gives a random array of size n and elements ranging
 from 1 to 2*n*/
int* sequence(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=rand() % (2*n)+1;
    }
    return a;
}
/*This function generates a best case for swpas od size n*/
int* caseB(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    return a;
}
/*This function generates a worst case for swpas od size n*/
int* caseA(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n-1;i++){
        a[i]=i+1;
    }
    a[n-1]=1;
    return a;
}
//this is decreasing order case which I called case C
int* caseC(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=n-i;
    }
    return a;
}
int main(){
    ofstream out;
    out.open("out.txt");
    int num=10; //number of random tires
    int range=100;//until what n to test
    cout <<"Enter the range until which n is tested:\n";
    cin >> range;
    cout <<"Enter sample size for each n:\n";
    cin >> num;
    out<< num << endl;
    srand(time(NULL));
    //selectSortShow(sequence(10),10);
    clock_t t;//needed for time measurements
    for(int n=1;n<range;n++){
        //we measure and output case A    
        for(int i=0;i<num;i++){
            int* a=caseA(n);
            t=clock();
            selectSort(a,n);
            t=clock()-t;
            out<<((float) t)/CLOCKS_PER_SEC<<" ";
        }
        //we measure and output case B:
        for(int i=0;i<num;i++){
            int* b=caseB(n);
            t=clock();
            selectSort(b,n);
            t=clock()-t;
            out<<((float) t)/CLOCKS_PER_SEC<<" ";
        }
        //we measure the output of case C:
        for(int i=0;i<num;i++){
            int* c=caseC(n);
            t=clock();
            selectSort(c,n);
            t=clock()-t;
            out<<((float) t)/CLOCKS_PER_SEC<<" ";
        }
        //here we have a random sequence
        for(int i=0;i<num;i++){
            int* seq=sequence(n);
            t=clock();
            selectSort(seq,n);
            t=clock()-t;
            out <<((float) t)/CLOCKS_PER_SEC << " ";
        }
        out << endl;
    }
    out.close();
    return 0;
}