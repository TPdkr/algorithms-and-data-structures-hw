/*
CH-231-A
a2_p3.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <deque>
class WindGauge {
    public:
        //constructor
        WindGauge(int period = 12);
        //adding a speed
        void currentWindSpeed(int speed);
        //function for highest speed 
        int highest() const;
        //function for lowest speed 
        int lowest() const;
        //function for average
        int average() const;
        //dump the info
        void dump();
    private:
        int per;
        int records;
        std::deque<int> log;
    // add properties and/or method(s) here
};