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
//naive recursion function for producing one fiboanchi number
int naiveRec(int n){
    if(n<=1){//base of recursion
        return n;
    } //recursion
    return naiveRec(n-1)+naiveRec(n-2);
}
//this funtion produces a fibonachi number using the bottom up approach
int bottomUp(int n){
    if (n<2){
        return n;
    }
    int a=1,pr1=1,pr2=0,nw;
    for(int i=3;i<=n;i++){
        pr2=pr1;
        pr1=a;
        nw=pr1+pr2;//create next
        a=nw;
    }
    return a;
}
long double five=sqrt(5);//square root of five
long double d=(1+five)/2;
//this funtion produces a fibonachi sequence using the closed from approach

long double closedForm(int n){
    if (n==0){
        long double f=1/five;
        return f;
    } else {
        return closedForm(n-1)*d;
    }
}
//this funtin returns an integer and was needed as the original one can 
//only return long double
int closed(int n){
    return ceil(closedForm(n));
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
int matrix(int n){
    int a;
    if(n<2){
        return n;
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
    for(int i=2;i<=n;i++){
        mul(mt,d);
        a=mt[1][0];
    }
    return a;
}
int main(){
    ofstream out;
    out.open("out.txt");
    ofstream table;//a file for creating a table
    int n=1000, m=100;//here i store the number of elements and sample number
    clock_t t;
    float maxtime=0.000005;//max execution time
    int test;//the test list
    //funtion pointers
    int (*fib[]) (int)={naiveRec, bottomUp, closed, matrix};
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
                out<< time <<" ";//save time
                //cout << test << " ";
            } else{
                //if exceed we stop counting
                break;
            }
        }
        //cout << endl;
        out << endl;
    }
    cout<< "Completed!\n";
    bottomUp(10);
    out.close();
    return 0;
}