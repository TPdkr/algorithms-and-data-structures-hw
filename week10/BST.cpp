/*
CH-231-A
a10_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include "BST.h"
#include <iostream>//neded for print function
//constrcutor
RedBlackTree::RedBlackTree(){
    Nil=new Node;
    Nil->data=-1;
    Nil->color=Color::BLACK;
    Nil->right=Nil;
    Nil->left=Nil;
    Nil->parent=Nil;
    root=Nil;
}

//=============================================================================
//in this section we have MODIFIER functions
//functions for rotation
void RedBlackTree::rotateRight(Node *y){
    Node* x=y->left;
    y->left=x->right;
    if(x->right!=Nil){
        x->right->parent=y;
    }
    x->parent=y->parent;
    if(y->parent==Nil){
        root=x;
    } else if(y==y->parent->left){
        y->parent->left=x;
    } else{
        y->parent->right=x;
    }
    x->right=y;
    y->parent=x;
}
//function for rotation left
void RedBlackTree::rotateLeft(Node *x){
    Node* y=x->right;
    x->right=y->left;
    if(y->left!=Nil){
        y->left->parent=x;
    }
    y->parent=x->parent;
    if(x->parent==Nil){
        root=y;
    } else if(x==x->parent->left){
        x->parent->left=y;
    } else{
        x->parent->right=y;
    }
    y->left=x;
    x->parent=y;
}
//isertion function fixup
void RedBlackTree::insertFixUp(Node * current){
    //we enter a loop
    while((current->parent->color==Color::RED)&&(current!=Nil)){
        if(current->parent==current->parent->parent->left){//cases 1-3
            Node* y=current->parent->parent->right;
            if(y->color==Color::RED){//case 1
                current->parent->color=Color::BLACK;
                y->color=Color::BLACK;
                current->parent->parent->color=Color::RED;
                current=current->parent->parent;
            } else{//case 2
                if(current==current->parent->right){
                    current=current->parent;
                    rotateLeft(current);
                }//case 3
                current->parent->color=Color::BLACK;
                current->parent->parent->color=Color::RED;
                rotateRight(current->parent->parent);
            } 
        }else{//cases 4-6
            //return;
            Node* y=current->parent->parent->left;
            if(y->color==Color::RED){//case 4
                current->parent->color=Color::BLACK;
                y->color=Color::BLACK;
                current->parent->parent->color=Color::RED;
                current=current->parent->parent;//we go up
            } else{
                if(current==current->parent->left){//case 5
                    current=current->parent;
                    rotateRight(current);
                }//case 6
                current->parent->color=Color::BLACK;
                current->parent->parent->color=Color::RED;
                rotateLeft(current->parent->parent);
            }
        }
        if(current==root){//we make sure that the tree's root is black
            break;
        }
    } 
    root->color=Color::BLACK;

}
//this function inserts an element into the tree. INSERT 
void RedBlackTree::insertRB(int value){
    //firsly we perform standard bst insert
    Node* newNode=new Node;//we create a node and fill it with data
    newNode->data=value;
    newNode->left=Nil;//no children yet
    newNode->right=Nil;
    Node* prev=Nil;
    Node* current=root;//we traverse the tree
    while(current!=Nil){
        prev=current;
        if(value<current->data){
            current=current->left;
        } else{
            current=current->right;
        }
    }//we found the place to insert the new node 
    newNode->parent=prev;
    if(prev==Nil){
        root=newNode;
    } else if(value<prev->data){
        prev->left=newNode;
    } else{
        prev->right=newNode;
    }
    //red and black part
    newNode->color=Color::RED;
    insertFixUp(newNode);//we fixup the tree

}
//-----------------------------------------------------------------------------
//DELETE and delete fixup as well as transplant function are here

//here we have the transplant function
void RedBlackTree::transplant(Node* to, Node* from){
    if(to->parent==Nil){
        root=from;//we tranpslant in place of the root
    } else if(to==to->parent->left){
        to->parent->left=from;//to is left child
    } else {
        to->parent->right=from;//to is right child
    }
    if(from!=Nil){//when we transpalant not Nil we need to change parent
        from->parent=to->parent;
    }
}
//here i put the fixup function for deleting an element
void RedBlackTree::deleteFixUp(Node* x){
    while((x!=root)&&(x->color==Color::BLACK)){
        if(x==x->parent->left){//cases 1-4 described on the slides
            Node* w=x->parent->right;
            if(w->color==Color::RED){//case 1
                w->color=Color::BLACK;
                x->parent->color=Color::RED;
                rotateLeft(x->parent);
                w=x->parent->right;
            }
            //case 2
            if((w->left->color==Color::BLACK)&&(w->right->color==Color::BLACK)){
                w->color=Color::RED;
                x=x->parent;
            } else{//case 3
                if(w->right->color==Color::BLACK){
                    w->left->color=Color::BLACK;
                    w->color=Color::RED;
                    rotateRight(w);
                    w=x->parent->right;
                }
                //case 4
                w->color=x->parent->color;
                x->parent->color=Color::BLACK;
                w->right->color=Color::BLACK;
                rotateLeft(x->parent);
                x=root;
            }
        }else{//the other 4 cases
            Node* w=x->parent->left;
            if(w->color==Color::RED){//case 5
                w->color=Color::BLACK;
                x->parent->color=Color::RED;
                rotateRight(x->parent);
                w=x->parent->left;
            }
            //case 6
            if((w->left->color==Color::BLACK)&&(w->right->color==Color::BLACK)){
                w->color=Color::RED;
                x=x->parent;
            } else{//case 7
                if(w->left->color==Color::BLACK){
                    w->right->color=Color::BLACK;
                    w->color=Color::RED;
                    rotateLeft(w);
                    w=x->parent->left;
                }
                //case 8
                w->color=x->parent->color;
                x->parent->color=Color::BLACK;
                w->left->color=Color::BLACK;
                rotateRight(x->parent);
                x=root;
            }
        }
    }
    x->color=Color::BLACK;
}


//here is our delete function
void RedBlackTree::deleteRB(Node *trash){
    if (trash==Nil){
        cout<<"can't delete Nil!"
        return;
    }
    Node* y=trash;//*
    Node* x;//*
    Color yOriginalColor=y->color;//we save the original color
    if(trash->left==Nil){//2 simple cases when a child is missing
        x=trash->right;//*
        transplant(trash, trash->right);
    } else if(trash->right==Nil){
        x=trash->left;//*
        transplant(trash, trash->left);
    } else{//both children are present
        y=minimum(trash->right);
        yOriginalColor=y->color;
        x=y->right;
        if(y->parent==trash){//*
            x->parent=y;
        }else {//we transplanr the y child 
            transplant(y, y->right);
            y->right=trash->right;
            y->right->parent=y;
        }
        //we put the next element after trash in its place
        transplant(trash, y);
        y->left=trash->left;
        y->left->parent=y;
        y->color=trash->color;//*
    }
    if(yOriginalColor==trash->color){//*
        deleteFixUp(x);
    }
    delete trash;

}

//=============================================================================
//QUERY functions are defined here

//internal function for minimum
Node* RedBlackTree::minimum(Node* x){
    while(x->left!=Nil){//we finc the left most child
        x=x->left;
    }
    return x;

}
//internal function for maximum
Node* RedBlackTree::maximum(Node* x){
    while(x->right!=Nil){//we find the right most child
        x=x->right;
    }
    return x;

}
//here the public minimum and maximum functions are defined
//they return Nil if there is nothing in the tree
Node* RedBlackTree::getMinimum(){
    Node* ret=minimum(root);
    (ret==Nil)?std::cout<<"No elements in the tree Nil node is returned\n"\
    : std::cout<<"";
    return ret;
}
Node* RedBlackTree::getMaximum(){
    Node* ret=maximum(root);
    (ret==Nil)?std::cout<<"No elements in the tree Nil node is returned\n"\
    : std::cout<<"";
    return ret;
}
//this is the function for finding a successor
Node* RedBlackTree::successor(const Node *x){
    if(x->right!=Nil){//simple case where the subtree isn't empty
        return minimum(x->right);
    }
    Node* y=x->parent;//2nd case
    while((y!=Nil)&&(x==y->right)){
        x=y;
        y=y->parent;
    }
    (y==Nil)? std::cout<<"That was the largest element of the tree\
    \nA Nil node with value -1 is returned\n" : std::cout<<"";
    return y;
}
//this is fir finding a predecessor
Node* RedBlackTree::predecessor(const Node* x){
    if(x->left!=Nil){//simple case where the subtree isn't empty
        return maximum(x->left);
    }
    Node* y=x->parent;//2nd case
    while((y!=Nil)&&(x==y->left)){
        x=y;
        y=y->parent;
    }
    (y==Nil)? std::cout<<"That was the smallest element of the tree\
    \nA Nil node with value -1 is returned\n" : std::cout<<"" ;
    return y;
}
//This is a search function used for the tree
Node* RedBlackTree::search(int goal){
    Node* current=root;
    //we stop if the element is found or the element is not there
    while((current->data!=goal)&&(current!=Nil)){
        if(current->data>goal){
            current=current->left;
        } else{
            current=current->right;
        }
    }
    //we return the found node or nil
    (current==Nil)? std::cout<<"No such node exists\
    \nA Nil node with value -1 is returned\n" : std::cout<<"" ;
    return current;
}

//=============================================================================
/*Here we have 2 functions and their recursive logic for printing. 
This allows for the abstraction of the user since there's no need for
arguements in the public print function*/
void RedBlackTree::printLogic(Node* a){//printing as sorted array
    if (a!=Nil){
        printLogic(a->left);//wew use recursion in both
        std::cout<<a->data<< " ";
        printLogic(a->right);
    }
}
void RedBlackTree::printThoroughLogic(Node* a){//printing all the internals
    if (a!=Nil){
        std::cout<<a->data<< " "<<"Children: l= "<<a->left->data<<" r= "<<a->right->data;
        if(a->color==Color::RED){
            std::cout<<" Color: Red\n";
        } else{
            std::cout<<" Color: Black\n";
        }
        printThoroughLogic(a->left);
        
        printThoroughLogic(a->right);
    }
}
//these are functions for printing the tree in 2 ways
void RedBlackTree::print(){
    printLogic(root);
    std::cout<<std::endl;
}
void RedBlackTree::printThorough(){
    printThoroughLogic(root);
    std::cout<<std::endl;
}
//=============================================================================
/*here is the loogic of the destructor*/
void RedBlackTree::cleaner(Node * a){
    if(a!=Nil){
        cleaner(a->left);
        cleaner(a->right);
        delete a;
    }
}
//here we have the destructor itself
RedBlackTree::~RedBlackTree(){
    cleaner(root);
}