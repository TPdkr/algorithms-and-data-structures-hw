/*
CH-231-A
a8_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
//this function is needed to print the arrays
template<typename T>
void prnt(T a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
//A
//this function sorts integers using the countsort algorithm
void countSort(int a[], int n){
    //we need to find k
    int mx=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    int k=mx;
    int c[k+1];
    int b[n];
    //here we start sorting
    for(int i=0; i<=k;i++){
        c[i]=0;
    }
    //we count here
    for(int i=0; i<n;i++){
        c[a[i]]+=1;
    }
    //prefix sums
    for(int i=1;i<=k;i++){
        c[i]=c[i]+c[i-1];
    }
    for(int j=n-1;j>-1;j--){
        b[c[a[j]]-1]=a[j];//putting back
        c[a[j]]--;
    }
    memcpy(a,b,sizeof(int)*n);//copy to the original array

}
/*this function performs inserion sort on a given slice of the list
we pass the list a as well as left and right edges of the slice*/
template <typename T>
void insertionSort( vector<T> a, int l, int r){
    int n=r-l;
    for(int j=1; j<n;j++){
        T key = a[l+j];
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
//B
//this algorithm uses bucket sort
void bucketSort(float a[], int n){
    vector<vector<float>> b;//vector of buckets
    for(int i=0;i<n;i++){
        vector<float> dummy;
        b.push_back(dummy);//we add the bucket
    }
    for(int i=0;i<n;i++){
        b[floor(n*a[i])].push_back(a[i]);//fill the buckets
    }
    for(int i=0;i<n;i++){
        insertionSort<float>(b[i],0,b[i].size());//we sort each bucket
    }
    int indx=0;
    //we unite all buckets back into a
    for(int i=0;i<n;i++){
        vector<float>::iterator it;
        for(it=b[i].begin(); it!=b[i].end();it++){
            a[indx]=*it;
            indx++;
        }
    }

}
//C 
//i modified the countsort to satisfy the condition
int countRange(int a[], int n, int start, int end){
    //we need to find k
    int mx=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    int k=mx;
    int c[k+1];
    //here we start sorting
    for(int i=0; i<=k;i++){
        c[i]=0;
    }
    //we count here
    for(int i=0; i<n;i++){
        c[a[i]]+=1;
    }
    //prefix sums
    for(int i=1;i<=k;i++){
        c[i]=c[i]+c[i-1];
    } 
    if (end>k){end=k;}
    if (start<=0){return C[end];}  
    return c[end]-c[start-1];

}
int main(){
    int cntsrt[]={9, 1, 6, 7, 6, 2, 1};
    int n=7;
    //cout<< countRange(cntsrt,n, 6,9);
    cout<<"Before count sort:\n";
    prnt<int>(cntsrt,n);
    countSort(cntsrt,n);//we sort the array
    cout<<"After count sort:\n";
    prnt<int>(cntsrt,n);//print the result
    cout<< endl;
    cout<<"Before bucket sort:\n";
    float bucketsrt[]={0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    cout<<"After bucket sort:\n";
    bucketSort(bucketsrt,n);//we sort the array
    prnt<float>(bucketsrt,n);//print the result
    cout<< endl;

    return 0;
}