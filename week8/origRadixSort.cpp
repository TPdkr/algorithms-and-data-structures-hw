/*
CH-231-A
a8_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//this is used in printing the result
template<typename T>
void prnt(vector<T> a, int n){
    for(int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
//we need to know the value of the bit
int getBit(int a, int pos){
    return (a&(1<<pos))>>pos;
}
//this is countsort function that sorts integers given the position and number
vector<int> countSort(vector<int>a, int n, int pos){
    //we need to find k
    int k=2;
    int c[k];
    vector<int> b;
    for(int i=0;i<n;i++){//we create the new array
        b.push_back(0);
    }
    //here we start sorting
    for(int i=0; i<=k;i++){//we create empty count array
        c[i]=0;
    }
    //we count here
    for(int i=0; i<n;i++){
        c[getBit(a[i],pos)]+=1;
    }
    //prefix sums
    for(int i=1;i<=k;i++){
        c[i]=c[i]+c[i-1];
    }
    for(int j=n-1;j>-1;j--){
        b[c[getBit(a[j],pos)]-1]=a[j];//putting back
        c[getBit(a[j],pos)]--;
    }
    return b;

}
//radix sort on a list of ints 
vector<int> radixSort(vector<int> a, int n){
    int mx=0;//we search for max value
    for(int i=0;i<n;i++){
        if(mx<a[i]){mx=a[i];}
    }
    int k=0;//we figure out the number of bits we will need
    while(pow(2,k)<mx){
        k++;
    }
    //we sort here
    for (int i=0;i<k;i++){
        a=countSort(a,n,i);//we call count sort
    }
    return a;
}
//this function performs the original radix sort
vector<int> ogSort(vector<int>a, int n, int pos){
    if (pos<0){//end of recursion
        return a;
    }
    vector<vector<int>> c;
    vector<int> b;
    vector<int> dummy1,dummy2;//we need storage
    c.push_back(dummy1);
    c.push_back(dummy2);
    for(int i=0; i<n;i++){
        c[getBit(a[i],pos)].push_back(a[i]);//we add
    }
    c[0]=ogSort(c[0], c[0].size(),pos-1);//recursion
    c[1]=ogSort(c[1], c[1].size(),pos-1);

    vector<int>::iterator it;
    for(int i=0;i<2;i++){//mergeing
        for(it=c[i].begin(); it!=c[i].end();it++){
            b.push_back(*it);
        }
    }
    return b;

}
//this is the original version of the algorithm that starts with the most 
//significant bit
vector<int> ogRadixSort(vector<int> a, int n){
    int mx=0;//we search for max value
    for(int i=0;i<n;i++){
        if(mx<a[i]){mx=a[i];}
    }
    int k=0;//we figure out the number of bits we will need
    while(pow(2,k)<mx){
        k++;
    }

    //we sort here
    a=ogSort(a,n,k);//we call count sort
    return a;
}
int main(){
    int a[]={2,4,1,5,6,7,2};
    int n=7;
    vector<int> b;
    for(int i=0;i<n;i++){
        b.push_back(a[i]);
    }
    cout<<"Initial array:\n";
    prnt<int>(b,n);
    cout<< "Sorted accorsing to the origianl algorith:\n";
    b=ogRadixSort(b,n);
    prnt<int>(b,n);
    cout<< "Sorted accorsing to the modern algorith:\n";
    b=radixSort(b,n);
    prnt<int>(b,n);
    return 0;
}