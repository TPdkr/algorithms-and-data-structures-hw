/*
CH-231-A
a7_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <ctime>
#include <cstring>
#include <vector>
using namespace std;

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

//this function checks if the array is sorted or not
int check(int a[], int n){
    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            return 0;
        }
    }
    return 1;
}
/*This functon partitions the array into 3 parts using the first 2 elements
as pivots.*/
void pivotFirst(int a[], int l, int r, int &pivot1, int &pivot2){
    int piv1, piv2;//we want the first pivot to be smaller than the second
    if(a[l]<a[l+1]){
        piv1=a[l];
        piv2=a[l+1];
    } else{
        piv1=a[l+1];
        piv2=a[l];
    }
    //vectors for subarrays
    vector<int> beg=vector<int>();
    vector<int> mid=vector<int>();
    vector<int> end=vector<int>();
    //we compare the elements and push them to the needed subsequence
    for(int i=l+2;i<r;i++){
        if(a[i]<=piv1){
            beg.push_back(a[i]);//<=pivot 1
        } else if(a[i]<=piv2){
            mid.push_back(a[i]);//pivot 1 < & <=pivot 2
        } else{
            end.push_back(a[i]);//>= pivot 2
        }
    }

    //we return the elements to the array
    int i=l;
    while(beg.size()!=0){//begging 
        a[i]=beg.back();
        beg.pop_back();
        i++;
    }
    a[i]=piv1;//pivot 1
    pivot1=i;
    i++;
    while(mid.size()!=0){//middle
        a[i]=mid.back();
        mid.pop_back();
        i++;
    }
    a[i]=piv2;//pivot 2
    pivot2=i;
    i++;
    while(end.size()!=0){//end
        a[i]=end.back();
        end.pop_back();
        i++;
    }
}
void pivotRandom(int a[], int l, int r, int &pivot1, int &pivot2){
    int piv1, piv2;
    int pl1=0,pl2=0;
    while(pl1==pl2){//we nned to make sure the pivots are not the same element
        pl1=l+rand()%(r-l);
        pl2=l+rand()%(r-l);
    }
    //we want the first pivot to be smaller than the second
    if(a[pl1]<a[pl2]){
        piv1=a[pl1];
        piv2=a[pl2];
    } else{
        piv1=a[pl2];
        piv2=a[pl1];
    }
    //vectors for subarrays
    vector<int> beg=vector<int>();
    vector<int> mid=vector<int>();
    vector<int> end=vector<int>();
    //we compare the elements and push them to the needed subsequence
    for(int i=l;i<r;i++){
        if((i!=pl1)&&(i!=pl2)){
            if(a[i]<=piv1){
                beg.push_back(a[i]);//<=pivot 1
            } else if(a[i]<=piv2){
                mid.push_back(a[i]);//pivot 1 < & <=pivot 2
            } else{
                end.push_back(a[i]);//>= pivot 2
            }
        }  
    }

    //we return the elements to the array
    int i=l;
    while(beg.size()!=0){//begging 
        a[i]=beg.back();
        beg.pop_back();
        i++;
    }
    a[i]=piv1;//pivot 1
    pivot1=i;
    i++;
    while(mid.size()!=0){//middle
        a[i]=mid.back();
        mid.pop_back();
        i++;
    }
    a[i]=piv2;//pivot 2
    pivot2=i;
    i++;
    while(end.size()!=0){//end
        a[i]=end.back();
        end.pop_back();
        i++;
    }
}
//this is the quicksort itself
void myQuickSort(int a[], int l, int r, void part(int [], int, int , int &, int &)){
    if(l<r-1){//condition for the base case
        int piv1;
        int piv2;//our pivots
        part(a,l,r,piv1,piv2);//partitioning
        myQuickSort(a,l,piv1,part);//recursion
        myQuickSort(a,piv1+1,piv2,part);
        myQuickSort(a,piv2+1, r,part);
    }
}
int main(){
    srand(time(NULL));//random initilised
    int n=1000;//length of array
    int times=100000;//how many times to try
    clock_t sumtime[]={0,0};//variable for summing the times
    clock_t t;//for time measuremnets
    int a[n],b[n];//random arrays
    int* newarray;//random array
    int** randomList=new int*[2];//list for storing the arrays
    randomList[0]=a;
    randomList[1]=b;
    string names[]={"First 2", "Random 2"};//names of the algorithms
    //pointers to algorithms
    void (*algorithms[]) (int [],int,int, int&, int&)={pivotFirst, pivotRandom};
    for(int j=0;j<times;j++){
        newarray=sequence(n);//we generate a sequence
        for(int alg=0;alg<2;alg++){
            memcpy(randomList[alg],newarray,n*sizeof(int));//copy
            t=clock();
            myQuickSort(randomList[alg],0,n, algorithms[alg]);//call
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
    for(int i=0;i<2;i++){
        cout<<"Average time of "<< names[i]<< " partition: "<<(float)sumtime[i]/(CLOCKS_PER_SEC*times)<< endl;
    }
    //delete []randomList;
    return 0;
}