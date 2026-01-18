/*
CH-231-A
a9_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <ctime>
using namespace std;
template<typename T>
class Tree;
//Here is our linked list class ===============================================
template<typename T>
class List{
    private:
        struct Node{//this is a list Node
	        T data;
	        Node* next; 
        };
        struct Node* start;
        struct Node* end;
	    int num; //number of elements
        //Aswer to 2C is provided here
        void toTreeLogic(Tree<T>& out, Node* current, int size){
            if (size==1){//base case when we have 1 element
                out.insert(current->data);
            } else if(size>1){
                Node* beg=current;
                for(int i=0; i<size/2;i++){//we move to the middle
                    current=current->next;
                }
                out.insert(current->data);//we put the data
                toTreeLogic(out, beg, size/2);//recursion
                toTreeLogic(out, current->next, size-size/2-1);
            }
            
        }
        
    public:
        List<T>(){//our constructor
            start=NULL;//default values
            end=NULL;
            num=0;
        }
        //we call the logic of conversion here. This structure simplifies the 
        //use outside the class and allows recursion
        Tree<T> toTree(){
            Tree<T> out=Tree<T>();//new tree we return
            toTreeLogic(out, start, num);//call of conversion
            return out;
        }
        int getNum(){return num;}
        //function for adding an element
        void add(T x){
            Node* newNode=new Node;//we create a node and fill it with data
            newNode->data=x;
            newNode->next=NULL;
            if(num==0){//if empty at start
                start=newNode;   
            } else{//if not need to update the end next
                end->next=newNode;
            }
            end=newNode;//we change the end node
            num++;        
        }
        //this function prints the linked list
	    void print(){
            for(Node* current=start; current!=NULL; current=current->next){
                cout<< current->data << " ";//printing data
            }
            cout<< endl;
        }
        //this function reverses the list according to the logic from 2a
        void reverse(){
            Node* prev=NULL;
            Node* nextNode=NULL;
            //we go through the list
            for(Node* current=start; current!=NULL; current=nextNode){
                nextNode=current->next;//we need to save next node pointer
                current->next=prev;
                prev=current;
            }
            //we update the end and start of the list
            start=prev;
            end=start;
        }
        ~List(){//desturctor
            Node* nextNode=NULL;
            for(Node* current=start; current!=NULL; current=nextNode){
                nextNode=current->next;
                delete current;
            }
        }

};
//Here we have a tree class====================================================
template<typename T>
class Tree{
    private:
        struct Node{//this is a list Node
	        T data;
	        Node* left; 
            Node* right;
        };
        struct Node* root;
	    int num; //number of elements
        //printing function logic which is separate due to recusiron
        void printLogic(Node* a){
            if (a!=NULL){
                printLogic(a->left);
                cout<<a->data<< " ";
                printLogic(a->right);
            }
        }
        //this is the logic behind the conversion
        //it's implemented here because it's recursive
        //Answer to 2B
        void conversionLogic(Node*a, List<T>& to){
            if(a!=NULL){
                conversionLogic(a->left, to);//we go left
                to.add(a->data);//add current
                conversionLogic(a->right, to);//we go right
            }
        }
        //this is needed for destructor since we allocate memory
        void desturctorLogic(Node* a){
            if(a!=NULL){
                desturctorLogic(a->left);
                desturctorLogic(a->right);
                delete a;
            }
        }
        /*this is a helper function to check the validity of conversion
        since its logarithmic it means that the tree is balanced and 
        has better search time than just a list*/
        int getHeight(Node* a){
            if(a==NULL){
                return 0;//base case
            } else{
                int leftHeight=getHeight(a->left);//we compute
                int rightHeight=getHeight(a->right);
                //we return the max height of children
                if(leftHeight>rightHeight){
                    return leftHeight+1;
                } else{
                    return rightHeight+1;
                }
            }
        }
        
    public:
        Tree<T>(){//our constructor
            root=NULL;//default values
            num=0;
        }
        //function for getting the size of the tree, as the number of elements
        int getNum(){return num;}
        //function for adding an element
        void insert(T x){
            Node* newNode=new Node;//we create a node and fill it with data
            newNode->data=x;
            newNode->left=NULL;//no children yet
            newNode->right=NULL;
            Node* prev=NULL;
            Node* current=root;//we traverse the tree
            while(current!=NULL){
                prev=current;
                if(x<current->data){
                    current=current->left;
                } else{
                    current=current->right;
                }
            }//we found the place to insert the new node 
            if(prev==NULL){
                root=newNode;
            } else if(x<prev->data){
                prev->left=newNode;
            } else{
                prev->right=newNode;
            }
            //increase counter
            num++;        
        }
        //this function prints the tree
        void print(){
            printLogic(root);//call logic of printing and recursion
            cout<<endl;
        }
        //this is answer to 2B!!! The recursoin is started here
        List<T> toList(){
            List<T> dest;//new list is created here
            conversionLogic(root, dest);//call of the function
            return dest;
        }
        int height(){//we can get the height here
            return getHeight(root);
        }
        ~Tree(){//destructor
            desturctorLogic(root);
        }	    
};

//generating a rnadom sequence
int* sequence(int n){
    int* a = new int[n];//create a new array
    for(int i=0;i<n;i++){
        a[i]=rand() % (2*n)+1;
    }
    return a;
}
int main(){
    //here i test the functions and the structures working
    srand(time(NULL));//random initilised
    List<int> ourList;
    int n=31;//the size if our data
    int b[n];
    for(int i=0;i<n;i++){//we fill the new list
        b[i]=i;
    }
    //here we test the list
    for(int i=0;i<n;i++){//we add the elemets
        ourList.add(b[i]);
    }
    cout<<"Initial list:\n";
    ourList.print();
    cout<<"Reversed list:\n";
    ourList.reverse();
    ourList.print();
    ourList.reverse();
    //here we test the tree type 
    int* bb=sequence(n);//we create a randon sequence to check the tree
    Tree<int> tree;
    for(int i=0;i<n;i++){//inserion
        tree.insert(bb[i]);
    }
    cout<<"A list of random numbers in a tree:\n";
    tree.print();

    //the conversion functions are called and tested
    cout<<"\n\nWE PERFORM CONVERSION:\n";
    List<int> newList=tree.toList();
    Tree<int> newTree=ourList.toTree();
    cout<<"A list converted to a tree:\n";
    newTree.print();
    cout<<"The height is "<< newTree.height()<<"\n";
    cout<<"A tree converted in a list\n";
    newList.print();
    return 0;
}