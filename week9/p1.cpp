/*
CH-231-A
a9_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
using namespace std;

//here we have a template of a stack for task 1a
template<typename T>
class Stack{
    private:
        struct StackNode {
            T data;
            StackNode *next;//this part is basically unchanged
        };
        StackNode *top;
        int size;
        int current_size;
    public:
        Stack(int new_size){//constructor
            size=new_size;
            current_size=0;
            top=NULL;
        }
        Stack(){
            size=-1;//we assign the default value
            current_size=0;
            top=NULL;
        }
        void push(T x){
            if (current_size>=size){
                //the stack is full check
                cout<<"Stack overflow! Can't add an element!\n";
                return;
            }
            current_size+=1;//incriese the size
            StackNode* newNode=new StackNode;//allocate memory
            newNode->next=top;//we fill the node with data
            newNode->data=x;
            top=newNode;//we change the top
        }
        T pop() {
            if(current_size<=0){
                cerr<<"Stack underflow can't delete an element!\n";
                //the stack is empty!
            } else{
                T ret=top->data;//the data we want to return
                StackNode *prev;
                prev=top;
                top=top->next;//shift the top
                delete prev;//delete the node
                current_size-=1;//we decrement the size
                return ret;
            }
        }
        //function for checking if it's empty
        bool isEmpty(){
            return current_size==0;//we just check the current size
        }
};
//1b here we have the implementation of the queue class 
template<typename T>
class Queue{
    private:
        int size;//similar to stack
        int current_size;
        Stack<T> *stack1;//2 stacks
        Stack<T> *stack2;
        //this function is needed to move all elements from one stack to
        // the other
        void move(Stack<T>* from, Stack<T>* to){
            while(!from->isEmpty()){
                to->push(from->pop());
            }
        }
    public:
        Queue(int value){//our constructor
            size=value;
            current_size=0;
            stack1=new Stack<T>(size);
            stack2=new Stack<T>(size);//we need space for all the elements
        }
        void enQueue(T x){
            if(current_size<size){
                stack1->push(x);//we add an element
                current_size+=1;//increase size
            } else{//its full! error
                cout<< "The Queue is full!\n";
            }
        }
        T deQueue(){
            if(current_size==0){//error message since can't return a vlaue
                cout<<"There are no elements to take!\n";
            } else {
                if(stack2->isEmpty()){//we move evrything to stack 2
                    move(stack1,stack2);
                }
                current_size-=1;//decrease size
                return stack2->pop();//return and pop
            }
        }
        //function for checking if it's empty
        bool isEmpty(){
            return current_size==0;//we just check the current size
        }
        ~Queue(){
            delete stack1;
            delete stack2;
        }
};
int main(){
    //a test for the functionality of the stack
    Stack<int> a=Stack<int>(5);
    int b[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){//we test push
        a.push(b[i]);
    }
    while(!a.isEmpty()){//and here i use isEmpty()
        cout<< a.pop()<< endl;//here we test pop
    }
    //here i tested the queue
    Queue<int> c=Queue<int>(5);
    for(int i=0;i<6;i++){//we test push
        c.enQueue(b[i]);
    }
    while(!c.isEmpty()){//we test deQueue method
        cout<< c.deQueue()<< endl;
    }

}