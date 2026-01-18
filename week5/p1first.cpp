/*
CH-231-A
a5_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;
//this is a fintion to print an array
void prnt(int* array, int n){
    for (int i=0; i<n; i++){
        cout<<array[i] << " ";
    }
    cout << endl;
}
void prntfile(int* array, int n, ofstream& out){
    for (int i=0; i<n; i++){
        out<<array[i] << " ";
    }
    out << endl;
}
//naive recursion function for producing one fiboanchi number
int naiveRec(int n){
    if(n<=1){//base of recursion
        return n;
    } //recursion
    return naiveRec(n-1)+naiveRec(n-2);
}
//this funtion produces a fibonachi sequence using the Naive approach
int* naiveRecGen(int n){
    //here we create a list and generate each element separately
    int* a = new int[n];
    for(int i=0;i<n;i++){
        a[i]=naiveRec(i);//call
    }
    return a;
}
//this funtion produces a fibonachi sequence using the bottom up approach
int* bottomUp(int n){
    int* a = new int[n];//new list
    for(int i=0;i<n;i++){
        if(i<=1){
            a[i]=i;//base case
        } else{
            a[i]=a[i-1]+a[i-2];//here we reference the previois elements
        }
    }
    return a;
}
//this funtion produces a fibonachi sequence using the closed from approach
int* closedForm(int n){
    int* a = new int[n];
    long double five=sqrt(5);//square root of five
    long double d=(1+five)/2;
    long double fi=1/five;
    for(int i=0;i<n;i++){
        a[i]=ceil(fi);//we round
        fi*=d;
    }
    return a;
}
/*This function is needed to do matrix multiplication for 2 2x2 matricies
it edits the first matrix and returns nothing*/
void mul(int a[2][2], int b[2][2]){
    int c[2][2];
    c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
    a[0][0]=c[0][0];
    a[0][1]=c[0][1];
    a[1][0]=c[1][0];
    a[1][1]=c[1][1];
}
//this funtion produces a fibonachi sequence using the matrix approach
int* matrix(int n){
    int* a = new int[n];
    for(int i=0;i<2;i++){//base case
        a[i]=i;
    }
    //we create the base matrix and the result matrix
    int mt[2][2];
    mt[0][0]=1;
    mt[1][0]=1;
    mt[0][1]=1;
    mt[1][1]=0;
    int d[2][2];
    d[0][0]=1;
    d[1][0]=1;
    d[0][1]=1;
    d[1][1]=0;
    //we multiply and record
    for(int i=2;i<n;i++){
        mul(mt,d);
        a[i]=mt[1][0];
    }
    return a;
}
int main(){
    ofstream out;
    out.open("out.txt");
    int n=100, m=50;//here i store the number of elements and sample number
    int* lists[4];//lresulting lists
    clock_t t;
    float maxtime=0.00005;//max execution time
    int* test=new int[n];//the test list
    int lengths[4];//lengths of resulting lists
    //funtion pointers
    int* (*fib[]) (int)={&naiveRecGen, &bottomUp, &closedForm, &matrix};
    for(int alg=0; alg<4;alg++){
        //we sample the time m times and average it
        for(int i=0;i<n;i++){
            clock_t sum=0;
            for(int j=0;j<m;j++){
                t=clock();
                test=(fib[alg])(i);//call
                t=clock()-t;
                sum+=t;
            }
            //conversion
            float time=((float) sum)/(CLOCKS_PER_SEC*m);
            if (time<maxtime){
                //save for output later on
                out<< time <<" ";//save time
                lists[alg]=(test);
                lengths[alg]=i;
            } else{
                //if exceed we stop counting
                break;
            }
        }
        out << endl;
    }
    ofstream table;//a file for creating a table
    table.open("table.txt");
    for(int i=0;i<4;i++){
        //output the lists into file
        prntfile(lists[i], lengths[i],table);
    }
    cout<< "Completed!\n";
    table.close();
    out.close();
    return 0;
}