/*
CH-231-A
a7_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
//fuction for swaping 2 elements
void swap(int a[], int indx1, int indx2){
    int swapEx=a[indx1];
    a[indx1]=a[indx2];
    a[indx2]=swapEx;
}
//a function for printing an array
void prnt(int a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
//generating a rnadom sequence
int* sequence(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=rand() % (2*n)+1;
    }
    return a;
}

//this fuction performs Lomoto partion and returns the index of pivot
int lomotoPart(int a[], int l, int r){
    int x=a[r-1];//pivot
    int i=l-1;
    for(int j=l; j<r-1;j++){
        if(a[j]<=x){
            i++;
            swap(a,i,j);//swap
        }
    }
    swap(a,r-1,i+1);
    return i+1;//returning pivot index
}
//Hoare partition algorithm
int hoarePart(int a[], int l, int r){
    int pivot=a[l];
    int i=l-1;
    int j=r+1;
    while(1){
        //prnt(a,8);
        do{
            i++;
        } while(a[i]<pivot);
        do{
            j--;
        } while(a[j]>pivot);
        if(i>=j){
            return j;
        }
        swap(a,i,j);
    }
}
//this function performs the partitioning around the median of three values
//the beginning the middle and the end
int medianPart(int a[], int l, int r){
    int beg=a[l], mid=a[(l+r)/2], end=a[r-1];//three points we compare
    int pivindx;//index of the pivot
    if((beg<mid)^(beg<end)){//we need to know which one is the median value
        pivindx=l;
    } else if((mid<beg)^(mid<end)){
        pivindx=(l+r)/2;
    } else {
        pivindx=r-1;
    }
    swap(a,r-1,pivindx);//we get the median at the end
    return lomotoPart(a,l,r);//we partition using Lomoto
}
/*this is the quicksort algorithm where you can pass a function to 
partition the array*/
void quickSortMy(int a[], int l, int r, int(part)(int [], int, int)){
    if(l<r){
        int prt=part(a,l,r);
        quickSortMy(a,l,prt,part);
        quickSortMy(a,prt+1,r,part);
    }
}
//this function checks if the array is sorted or not
int check(int a[], int n){
    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    srand(time(NULL));//random initilised
    int n=1000;//length of array
    int times=100000;//how many times to try
    clock_t sumtime[]={0,0,0};//variable for summing the times
    clock_t t;//for time measuremnets
    int a[n],b[n],c[n];//random arrays
    int* newarray;//random array
    int** randomList=new int*[3];//list for storing the arrays
    randomList[0]=a;
    randomList[1]=b;
    randomList[2]=c;
    string names[]={"Lomoto", "Median","Hoare"};//names of the algorithms
    //pointers to algorithms
    int (*algorithms[]) (int [],int,int)={lomotoPart, medianPart, hoarePart};
    for(int j=0;j<times;j++){
        newarray=sequence(n);//we generate a sequence
        for(int alg=0;alg<3;alg++){
            memcpy(randomList[alg],newarray,n*sizeof(int));//copy
            t=clock();
            quickSortMy(randomList[alg],0,n, algorithms[alg]);//call
            t=clock()-t;//measure
            sumtime[alg]+=t;//add to sum in order to average
            if(!check(randomList[alg],n)){//check for correctness
                prnt(randomList[alg],n);
                cout<<"Algorithm: " << alg <<"\nTry is "<< j<<"\nERROR!\n";
                j=times*2;
                break;
            }
        }
    }
    //here we print and avergae the results
    for(int i=0;i<3;i++){
        cout<<"Average time of "<< names[i]<< " partition: "<<(float)sumtime[i]/(CLOCKS_PER_SEC*times)<< endl;
    }
    delete []randomList;
    return 0;
}