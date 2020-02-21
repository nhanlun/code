#include "BST.h"

Node::Node()
{
    pLeft = pRight = nullptr;
}

Node::Node(int x) : Node()
{
    data = x;
}

Node::~Node()
{
    delete pLeft;
    delete pRight;
}

BST::BST()
{
    pRoot = nullptr;
}

BST::~BST()
{
    delete pRoot;
}

void BST::insert(int x)
{
    theRealInsert(pRoot, x);
}

void BST::theRealInsert(Node *&pRoot, int x)
{
    if (pRoot == nullptr)
        pRoot = new Node(x);
    if (pRoot->data == x)
        return;
    if (pRoot->data > x)
        theRealInsert(pRoot->pLeft, x);
    else 
        theRealInsert(pRoot->pRight, x);
}

void BST::print()
{
    theRealPrintInorder(pRoot);
}

void BST::theRealPrintInorder(Node* pRoot)
{
    if (pRoot==nullptr) return;
    theRealPrintInorder(pRoot->pLeft);
    std::cout << pRoot->data << ' ';
    theRealPrintInorder(pRoot->pRight);
}