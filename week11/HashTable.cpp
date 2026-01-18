/*
CH-231-A
a11_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include "HashTable.h"
#include <iostream>
//=============================================================================
//NODE
//the constructor for the Node
Node::Node(int newKey,int NewValue){
    key=newKey;
    value=NewValue;
}
//=============================================================================
//HASHTABLE
//the default constructor
HashTable::HashTable(){
    arr=NULL;
    maxSize=0;
    currentSize=0;
}
//the constrcutot for a given size
HashTable::HashTable(int size){
    arr=new Node*[size];
    //this is the default state for all nodes
    for(int i=0; i<size;i++){
        arr[i]=NULL;
    }
    //we set max size and current size
    maxSize=size;
    currentSize=0;
}
//the hash function
int HashTable::hashCode(int key){
    return (key % 37) % maxSize;
}
//function for double hashing
int HashTable::hashCode2(int key){
    return (key % 133) % maxSize;
}
//this is function for hashing that includes i
int HashTable::hash(int key, int i){
    return (hashCode(key)+hashCode2(key)*i)%maxSize;
}
//function for inserting an element
void HashTable::insertNode(int key, int value){
    if(currentSize==maxSize){//the table is full
        std::cerr<<"Table overflow!!\n";
        return;
    }
    int i=0;//the variable i for clashes 
    while(i<maxSize){
        //current index we try
        int j=hash(key,i);
        if (!arr[j]){
           arr[j]=new Node(key, value); 
           currentSize++;
           return;
        } else {
            i+=1;
        }
    }
    std::cerr<<"Table overflow\n";
}
//get function
int HashTable::get(int searchKey){
    int i=0;
    while(i<maxSize){
        int j=hash(searchKey,i);
        //there is no element for key
        if(arr[j]==NULL){
            break;
        }
        if (arr[j]->key==searchKey){//we found it
           return arr[j]->value;
        } else {//we search next possible position
            i+=1;
        }
        
    }
    std::cout<<"No such element found\n";
    return -1;
}
//the is empty function for the hash table
bool HashTable::isEmpty(){return currentSize==0;}
//the destructor
HashTable::~HashTable(){
    for (int i=0;i<maxSize;i++){
        delete arr[i];//we free all memory
    }
    delete []arr;
}
