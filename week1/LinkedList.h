/*
CH-231-A
a1_p3.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
//here's our template declaration 
#include <cstddef>
//a struct for Node of the list
template <class T>
struct Node{
    T obj;
    Node<T>* next;
    Node<T>* prev;
};
//a double linked list class
template <class T>
class List{
    private:
        Node<T>* start;
        Node<T>* end;
        int num;
    public:
        //constructot
        List(){
            //initialize everything to NULL and 0
            start=NULL;
            end=NULL;
            num=0;
        }
        //destructor
        ~List(){
            while (num)
            {
                Node<T> *cursor = start;
                start = start->next;
                num--;
                delete cursor;
            }
        }
        //method for returning the first element
        T first(){
            return start->obj;
            
        }
        //method for returning the first element
        T last(){
            return end->obj;
        }
        //method for deleting the last element and returning it
        T dlast(){
            if (num>0){//check if can delete
                T ret=end->obj;
                Node<T>* cur=end;
                if(end->prev!=NULL){//is there a next element
                    end=end->prev;
                    end->next=NULL;
                }
                num--;//decrease the number of elements
                delete cur;
                return ret;
            }
        }
        //method for deleting the first element and returning it
        //these give us the warning because sometimes they cannot retrieve 
        //a value when it is empty
        T dfirst(){
            if(num>0){//check if can delete
                T ret=start->obj;
                Node<T>* cur=start;
                if(start->next!=NULL){//is there a next element
                    start=start->next;
                    start->prev=NULL;
                }
                num--;//decrease the number of elements
                delete cur;
                return ret;
            }
            
        }
        //add first element 
        void addf(T elm){
            num++;
            Node<T>* nw;
            nw=new Node<T>;
            nw->obj=elm;
            nw->prev=NULL;
            nw->next=start;
            //is there a next element?
            if (start!=NULL){
                start->prev=nw;
            }
            start=nw;
            //check if the list is empty
            if (end==NULL){
                end=nw;
            }
        }
        //add last element
        void addl(T elm){
            num++;
            Node<T>* nw;
            nw=new Node<T>;
            nw->obj=elm;
            nw->next=NULL;
            nw->prev=end;
            //is there a previous element?
            if (end!=NULL){
                end->next=nw;
            }
            end=nw;
            //check if the list is empty
            if (start==NULL){
                start=nw;
            }
        }
        //method for returning the number of elements
        int numb(){return num;}
};

