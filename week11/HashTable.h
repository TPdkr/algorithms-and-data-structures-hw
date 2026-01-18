/*
CH-231-A
a11_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
class Node {//our node class
    public:
        int key;
        int value;
        Node(int key, int value);
};
class HashTable {//the hash table class
    private:
        Node ** arr;//converted to * from **
        int maxSize;
        int currentSize;
    public:
        HashTable();
        HashTable(int);//new constructor
        int hashCode(int);//the hash function for our table
        int hashCode2(int);//the second hash function for double hashing
        int hash(int,int);//this is function for actual hash value used
        void insertNode(int, int);
        int get(int);
        bool isEmpty();
        ~HashTable();
};