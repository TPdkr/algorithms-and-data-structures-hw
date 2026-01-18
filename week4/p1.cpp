/*
CH-231-A
a4_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
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
int* caseA(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    return a;
}
//this is decreasing order case which is the worst
int* caseB(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=n-i;
    }
    return a;
}
/*this function performs inserion sort on a given slice of the list
we pass the list a as well as left and right edges of the slice*/
void insertionSort( int* a, int l, int r){
    int n=r-l;
    for(int j=1; j<n;j++){
        int key = a[l+j];
        int i=j-1;
        //while loop where we go thorugh the list
        while ((i>-1) && (a[l+i]>key)){
            a[l+i+1]=a[l+i];
            i--;
        }
        //assign value stored in key
        a[l+i+1]=key;
    }
}
//this is a fintion to print an array
void prnt(int* array, int l,int r){
    for (int i=0; i<r-l; i++){
        cout<<array[l+i] << " ";
    }
    cout << endl;
}
/*
Here we have the merge sort funtion that takes k as well as pointer to
a and the edges of the slice as l and r*/
void mergeSort(int k, int* a, int l, int r){
    //this is the middle
    int mid=(r+l)/2;
    if (r-l<=k){
        //here we call insertion sort for a
        insertionSort(a,l,r);
    } else{
        //recursion
        mergeSort(k,a,l,mid);
        mergeSort(k,a,mid,r);
    }
    //here is the actual merging part
    int lf[mid-l+1];
    int rt[r-mid+1];
    //we copy the contents into the new lists
    for(int i=l; i<mid;i++){
        lf[i-l]=a[i];
    }
    for(int i=mid; i<r;i++){
        rt[i-mid]=a[i];
    }
    //we save a large number instead of infinity as last element
    lf[mid-l]=100000;
    rt[r-mid]=100000;
    int i=0;
    int j=0;
    //now we unite them into a 
    for (int k=l; k<r;k++){
        if(lf[i]<=rt[j]){
            a[k]=lf[i];
            i++;
        } else{
            a[k]=rt[j];
            j++;
        }
    }
}
int main(){
    //I reused dome of the code from my previous homework
    ofstream out;
    out.open("out.txt");
    int num; //number of random tires
    int n;
    cout <<"Enter the range until which n is tested:\n";
    cin >> n;
    cout <<"Enter sample size for each k:\n";
    cin >> num;
    out<< num << endl;
    out << n << endl;
    srand(time(NULL));
    //selectSortShow(sequence(10),10);
    clock_t t;//needed for time measurements
    for(int k=1;k<n;k++){
        //we measure and output case A    
        for(int i=0;i<num;i++){
            int* a=caseA(n);
            t=clock();
            mergeSort(k,a,0,n);
            t=clock()-t;
            out<<((float) t)/CLOCKS_PER_SEC<<" ";
            delete []a;
        }
        //we measure and output case B:
        for(int i=0;i<num;i++){
            int* b=caseB(n);
            t=clock();
            mergeSort(k,b,0,n);
            t=clock()-t;
            out<<((float) t)/CLOCKS_PER_SEC<<" ";
            delete []b;
        }
        //here we have a random sequence
        for(int i=0;i<num;i++){
            int* seq=sequence(n);
            t=clock();
            mergeSort(k,seq,0,n);
            t=clock()-t;
            out <<((float) t)/CLOCKS_PER_SEC << " ";
            delete []seq;
        }
        out << endl;
    }
    out.close();
    return 0;
}