/*
CH-231-A
a2_p3.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include "WindGauge.h"
using namespace std;
int main(){
    WindGauge a;
    //a.dump(); -corner case that works
    //arrays with values
    int first[5]={15, 16, 12, 15, 15};
    int scnd[10]={16, 17, 16, 16, 20, 17, 16, 15, 16, 20};
    //adding speed
    for(int i=0;i<5;i++){
        a.currentWindSpeed(first[i]);
    }
    //output
    a.dump();
    //adding speed
    for(int i=0;i<10;i++){
        a.currentWindSpeed(scnd[i]);
    }
    //output
    a.dump();
    return 0;
}