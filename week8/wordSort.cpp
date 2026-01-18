/*
CH-231-A
a8_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//this is used in printing the result
template<typename T>
void prnt(vector<T> a, int n){
    for(int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
//this functions returns the value for sorting and is needed as a safety
//mechanism when the index exceeds the lenght
int getChar(string a, int pos){
    if((int)a.size()<=pos){
        //return (int)a[a.size()-1];
        return  0;
    } else{
        return (int)a[pos];
    }
}

//this algorithm performs count sort on a given list of strings based on a certain position
vector<string> countSort(vector<string> a, int n, int pos){
    //we need to find k
    int mx=getChar(a[0],pos);
    for(int i=1;i<n;i++){//we determine the range
        if(getChar(a[i],pos)>mx){
            mx=getChar(a[i],pos);
        }
    }
    int k=mx;
    int c[k+1];
    vector<string> b;
    for(int i=0;i<n;i++){//we create the new array
        b.push_back("");
    }
    //here we start sorting
    for(int i=0; i<=k;i++){//we create empty count array
        c[i]=0;
    }
    //we count here
    for(int i=0; i<n;i++){
        c[getChar(a[i],pos)]+=1;
    }
    //prefix sums
    for(int i=1;i<=k;i++){
        c[i]=c[i]+c[i-1];
    }
    for(int j=n-1;j>-1;j--){
        b[c[getChar(a[j],pos)]-1]=a[j];//putting back
        c[getChar(a[j],pos)]--;
    }
    return b;

}
//radix sort on a list of string given their max size
vector<string> radixSort(vector<string> a, int n, int k){
    for (int i=k-1;i>-1;i--){
        a=countSort(a,n,i);//we call count sort
    }
    return a;
}
//this is needed to turn a list into a vector as well as figure out the size
vector<string> wordSort(string a[], int n){
    vector<string> b;
    long unsigned int mx=a[0].size();
    for(int i=0;i<n;i++){
        b.push_back(a[i]);
        if(mx<b[i].size()){
            mx=b[i].size();
        }
    }
    return radixSort(b,n,mx);
}
int main(){
    //the list of words
    string a[]={"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
    int n=10;//the number
    vector<string> b;
    b=wordSort(a,n);//call of function
    cout<< "Sorted sequence is:\n";
    prnt<string>(b,n);//output
    return 0;
}