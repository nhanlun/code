#ifndef BST_h
#define BST_h

#include <bits/stdc++.h>

struct Node 
{
    int data;
    Node* pLeft;
    Node* pRight;
    Node();
    Node(int x);
    ~Node();
};

class BST
{
private:
    Node* pRoot;
    void theRealInsert(Node*& pRoot, int x);
    void theRealPrintInorder(Node* pRoot);
public:
    BST();
    ~BST();
    void insert(int x);
    void print();
};

#endif