/*
CH-231-A
a2_p3.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <deque>
#include <iostream>
#include "WindGauge.h"
//constructor for the class 
WindGauge::WindGauge(int period){
    std::deque<int> log;
    per=period;
    records=0;
}
//a function for adding an element 
void WindGauge::currentWindSpeed(int speed){
    log.push_back(speed);
    if(records<per){
        records++;
        //increment
    } else{
        //if full we need to take out an element 
        log.pop_front();
    }
}
//a function for highest speed
int WindGauge::highest() const{
    //test for corner case-empty
    if (records>0){
        int mx=log[0];
        for(int i=0;i<records;i++){
            if (log[i]>mx){ mx=log[i];}
        }
        return mx;
    } else {
    //basically an error we don't have anything to return
     return -1;
    }
}
//function for lowest speed 
int WindGauge::lowest() const{
    //test for corner case-empty
    if (records>0){
        int mn=log[0];
        for(int i=0;i<records;i++){
            if (log[i]<mn){ mn=log[i];}
        }
        return mn;
    } else {
    //basically an error we don't have anything to return
     return -1;
    }    
}
//function for average
int WindGauge::average() const{
    int sm=0;
    for(int i=0;i<records;i++){
        sm+=log[i];
    }
    //we cant't devide by zero
    //check for non empty
    if (records>0){
        return sm/records;
    } else{
        return -1;
    }
}
//this function dumps min, max and average speed 
void WindGauge::dump(){
    std::cout << "Mininmum speed: " << this->lowest() << std::endl;
    std::cout << "Maximum speed: " << this->highest() << std::endl;
    std::cout << "Average speed: " << this->average() << std::endl;
    std::cout << std::endl;
}
