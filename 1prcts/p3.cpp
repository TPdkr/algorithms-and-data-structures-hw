#include <iostream>
using namespace std;
template <class T>
void multiples(T& sum, T x, int n){
    sum=1+x*(1+n)*n/2;
}
int main(){
    int sum=0, x=2;
    multiples<int>(sum,x,3);
    cout<< sum<< endl;
}