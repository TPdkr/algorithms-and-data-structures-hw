/*
CH-231-A
a6_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
//generating a rnadom sequence
int* sequence(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=rand() % (2*n)+1;
    }
    return a;
}
//this void function can be used to print a list. 
//I used it for checking how the code is working
void prnt(int a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
//these 2 functions return the left anf right element of binary heap
//here the formula accounts for index starting with 0
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
//maxheapify function
void maxheapify(int a[], int i, int n){
    int l=left(i);//we get left and right
    int r=right(i);
    int largest=i;
    //we find the largest
    if ((l<n) && (a[l]>a[i])){
        largest=l;
    }
    if((r<n)&&(a[r]>a[largest])){
        largest=r;
    }
    //swap if needed
    if(largest!=i){
        int c=a[i];
        a[i]=a[largest];
        a[largest]=c;
        maxheapify(a,largest,n);//recursion
    }

}
//function for building max heap
void buildmaxheap(int a[], int n){
    for(int i=n/2-1;i>=0;i--){
        maxheapify(a,i,n);//calling maxheapify
    }

}
//the actual heapsort function
void heapsort(int a[], int n){
    buildmaxheap(a,n);//we build the max heap
    for(int i=n-1;i>=1;i--){//we iterate
        int c=a[0];
        a[0]=a[i];
        a[i]=c;
        n--;//decrease the size of the heap
        maxheapify(a,0,n);//call max heapify
    }

}
//search function
int search(int a[], int i, int n){
    int j=i;
    while(right(j)<n){
        if(a[right(j)]>a[left(j)]){
            j=right(j);
        } else{
            j=left(j);
        }
    }
    if(left(j)<n){
        j=left(j);
    }
    return j;
}
//function for floating down the value
void floatdown(int a[], int i, int n){
    int j=search(a,i,n);
    while(a[i]>a[j]){
        j=j/2;
    }
    while(j>i){
        int c=a[i];
        a[i]=a[j];
        a[j]=c;
        j=j/2;
    }
}
//here we have bottom up heapsort
void modheapsort(int a[], int n){
    buildmaxheap(a,n);//we build the max heap
    for(int i=n-1;i>=1;i--){//we iterate
        int c=a[0];
        a[0]=a[i];
        a[i]=c;
        n--;//decrease the size of the heap
        floatdown(a,0,n);//modified part

    }
}
int main(){
    ofstream out;
    out.open("out.txt");//open file
    srand(time(NULL));//random initilised
    int n=1000, m=20;//here i store the number of elements and sample number
    void (*algorithms[]) (int [], int )={heapsort, modheapsort};
    clock_t t;
    for(int alg=0;alg<2;alg++){
        for(int i=1;i<=n;i++){
            clock_t sum=0;
            for(int j=0;j<m;j++){
                t=clock();//we measure the time
                algorithms[alg](sequence(i),i);
                t=clock()-t;
                sum+=t;
            }
            //conversion
            out<<((double) sum)/((double)CLOCKS_PER_SEC*(double)m)<< " ";
        }
        out<< endl;
    }
    cout<< "Completed!\n";
    out.close();
    return 0;
}