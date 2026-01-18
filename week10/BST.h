/*
CH-231-A
a10_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
enum Color {RED, BLACK};
struct Node{
    int data;
    Color color;
    Node *left, * right, * parent;
};
class RedBlackTree {
    private:
        Node* root;
        Node* Nil;//needed for leafes
    protected:
        void rotateLeft(Node *);
        void rotateRight(Node *);
        void printLogic(Node *);//for printing
        void printThoroughLogic(Node *);//for complete prinitng
        void insertFixUp(Node *);//for fixing up
        void cleaner(Node*);//for the destructor
        void transplant(Node *, Node *);//the transplant function
        void deleteFixUp(Node *);//for fixing after delete
        Node * minimum(Node *);
        Node * maximum(Node *);
    public:
        RedBlackTree();
        void print();//for the user
        void printThorough();//to print data
        void insertRB(int);
        void deleteRB(Node *);
        Node * predecessor(const Node *);
        Node * successor(const Node *);
        Node * getMinimum();
        Node * getMaximum();
        Node * search(int);
        ~RedBlackTree();//destructor i created
};