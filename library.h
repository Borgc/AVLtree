#ifndef BINTREE_LIBRARY_H
#define BINTREE_LIBRARY_H
//write tests for STree and AVL
#include <iostream>
#include <list>
class Node {
    int key;
    Node *left, *right;
    int height;
    int bal;
public:
    explicit Node(int k = 0, uint8_t height = 1, uint8_t bal = 0, Node *l = nullptr, Node *r = nullptr);
    void RecCopy(Node *q, Node *p);
    int GetKey() const{return key;}
    void DelChild(Node *q);

    int8_t GetHeight() const;
    int8_t GetBalance();
    void UpdateHeight();
    friend Node * RRot(Node *q);
    friend Node * LRot(Node *q);
    friend Node * Balance(Node *node);
    friend class STree;
    friend class AVL;
};

class STree {
protected:
    Node *root;
public:
    STree(){root = nullptr;}
    explicit STree(int n);
    STree(const STree &st);
    STree(int32_t* arr, size_t size);
    ~STree();

    STree & operator = (const STree T);
    Node *GetRoot(){return root;}
    Node *GetMin() const;
    Node *GetMax() const;

    void PrintTree(Node *q, int k);

    void inarray(Node *q, int *a, int &k);
    void inarray1(Node *q, int *a, int &k);
    void inarray2(Node *q, int *a, int &k);
    void inarray3(Node *q, int *a, int &k);
    int LNR(int* a);
    int RNL(int* a);
    int NLR(int* a);
    int LRN(int* a);
    void LevelTrav(std::list <Node *> & list) const;
    void print_leafes(Node* q);
    Node * SearchNode(int n);
    void Add(int k);
    void DelNode(int key);
};
class AVL : public STree {
public:
    AVL(int * a, int size);
    AVL(int n);
    Node * bAdd(int x, Node *p, bool &h);
    void insert(int x);
    void Del(int k);

private:
    Node *DelTmp(Node *q);
    Node *RecAdd(Node *q, int key);
    Node *RecDel(Node *q, int key);


    void balanceL(Node *p, bool &h);

    void balanceR(Node *p, bool &h);

    Node *delete1(int x, Node *p, bool &h);
};



#endif //BINTREE_LIBRARY_H
