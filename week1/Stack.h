/*
CH-231-A
a1_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
//here's our template declaration 
template <class T>
class Stack{
    private:
        T* p;
        int num;
        int size;
    public:
    //constructor size 10
        Stack(){p=new T[10]; num=0; size=10;}
    //copy constructor
        Stack(const Stack& a){
            p=new T[a.size];
            num=a.num;
            size=a.size;
            for(int i=0;i<size;i++){
                p[i]=a.p[i];
            }
        }
    //constructor size n, defined by user
        Stack(int n){
            p=new T[n]; num=0; size=n;
        }
    //a push method for adding an element
        bool push(T element){
            if (num==size){//is full?
                return 0;
            } else {
                p[num]=element;
                num++;
                return 1;
            }
        }
    //a pop method for deleting the last element in the stack
        bool pop(T& out){
            if (num==0){//is empty?
                return 0;
            } else {
                out=p[num-1];
                num--;
                return 1;
            }
        }
    //method that returns the last element
        T back(void){
            return p[num-1];
        }
    //how many elements in the stack at the moment
        int getNumEntries(){
            return num;
        }
    //destructor
        ~Stack(){
            delete []p;
        }


};