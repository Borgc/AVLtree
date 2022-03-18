#include "library.h"

#include <iostream>
Node::Node(int k, uint8_t height, uint8_t bal, Node *l, Node *r) {
    this->key = k;
    this->height = height;
    this->bal = bal;
    this->left = l;
    this->right = r;
}
void Node::DelChild(Node *q) {
    if(q == nullptr){
        return;
    }
    DelChild(q->left);
    DelChild(q->right);
    delete q;
}

void Node::RecCopy(Node *q, Node *p) {
    if(q->left != nullptr){
        p->left = new Node(q->left->key, q->left->height);
        RecCopy(q->left, p->left);
    }
    if(q->right != nullptr){
        p->right = new Node(q->right->key, q->right->height);
        RecCopy(q->right, p->right);
    }
}
int8_t Node::GetHeight() const {
    return height;
}
int8_t Node::GetBalance(){
    auto r = right ? right->GetHeight() : 0;
    auto l = left ? left->GetHeight() : 0;
    bal = int8_t (r - l);
    return int8_t(r - l);
}
void Node::UpdateHeight() {
    if(this == nullptr)return;
    auto l = left ? left->height : 0;
    auto r = right ? right->height : 0;
    height = ((l > r) ? l : r) + 1;
}
Node* RRot(Node* q) {
    Node* new_root = q->left;
    if (new_root == nullptr) {
        return q;
    }
    q->left = new_root->right;
    new_root->right = q;
    q->UpdateHeight();
    new_root->UpdateHeight();
    return new_root;
}
Node* LRot(Node* q) {
    Node* new_root = q->right;
    if (new_root == nullptr) {
        return q;
    }
    q->right = new_root->left;
    new_root->left = q;
    q->UpdateHeight();
    new_root->UpdateHeight();
    return new_root;
}


Node* Balance(Node* node) {
    node->UpdateHeight();
    if (node->GetBalance() > 1) {
        if (node->right->GetBalance() < 0) {
            node->right = RRot(node->right);
        }
        return LRot(node);
    }

    if (node->GetBalance() < -1) {
        if (node->left->GetBalance() > 0) {
            node->left = LRot(node->left);
        }
        return RRot(node);
    }

    return node;
}
STree::STree(int n){
    if(n == 0){
        root = nullptr;
    } else {
        root = new Node(rand()%100);
        for(int i = 1; i < n; i++){
            Add(rand()%100);
        }
    }
}
STree::STree(const STree &T){
    if(T.root == nullptr) {
        root = nullptr;
        return;
    }
        root = new Node(T.root->GetKey());
        T.root->RecCopy(T.root, root);
}
STree::STree(int32_t *arr, size_t size) {
    if(size == 0){
        root = nullptr;
        return;
    }
    root = new Node(arr[0]);
    for(auto i = 1; i < size; i++){
        Add(arr[i]);
    }
}
STree::~STree() {
    root->DelChild(root);
    root = nullptr;
    //delete root;
}
STree &STree::operator=(const STree T) {
    if(this == &T)return *this;
    this->~STree();
    if(T.root == nullptr){
        root = nullptr;
        return *this;
    }
    root = new Node(T.root->GetKey());
    T.root->RecCopy(T.root, root);
    return *this;
}

Node *STree::GetMin() const{
    if(root == nullptr)return nullptr;
    Node *q = root;
    while(q->left != nullptr){
        q = q->left;
    }
    return q;
}
Node *STree::GetMax() const{
    if(root == nullptr)return nullptr;
    Node *q = root;
    while(q->right != nullptr){
        q = q->right;
    }
    return q;
}
void STree::PrintTree(Node *q, int k){
    if(q == nullptr)return;
    PrintTree(q->right, k+3);
    for(int i = 0; i < k; i++)std::cout << " ";
    std::cout.width(2);
    std::cout << q->key << std::endl;
    PrintTree(q->left, k+3);
}
int STree::LNR(int* a){
    int k = 0;
    inarray(root, a, k);
    return k;
}
void STree::inarray(Node *q, int *a, int &k){
    if(q == nullptr)return;
    inarray(q->left, a, k);
    a[k++] = q->key;
    inarray(q->right, a, k);
}
int STree::RNL(int* a){
    int k = 0;
    inarray1(root, a, k);
    return k;
}
void STree::inarray1(Node *q, int *a, int &k){
    if(q == nullptr)return;
    inarray1(q->right, a, k);
    a[k++] = q->key;
    inarray1(q->left, a, k);
}
int STree::NLR(int* a){
    int k = 0;
    inarray2(root, a, k);
    return k;
}
void STree::inarray2(Node *q, int *a, int &k){
    if(q == nullptr)return;
    a[k++] = q->key;
    inarray2(q->left, a, k);
    inarray2(q->right, a, k);
}
int STree::LRN(int* a){
    int k = 0;
    inarray3(root, a, k);
    return k;
}
void STree::inarray3(Node *q, int *a, int &k){
    if(q == nullptr)return;
    inarray3(q->left, a, k);
    inarray3(q->right, a, k);
    a[k++] = q->key;
}
void STree::LevelTrav(std::list <Node *> & list) const{
    if(root == nullptr){
        return;
    }
    list.push_back(root);
    for(auto it : list){
        if(it->left != nullptr){
            list.push_back(it->left);
        }
        if(it->right != nullptr){
            list.push_back(it->right);
        }
    }
}
void STree::print_leafes(Node* q){
    if(root->left == nullptr && root->right == nullptr){
        std::cout << root->key;
        return;
    }
    if(q->left != nullptr){
        print_leafes(q->left);
    }
    if(q->right != nullptr){
        print_leafes(q->right);
    }
}

void STree::Add(int k) {
    if(root == nullptr){
        root = new Node(k);
        return;
    }
    Node *sNode = root;
    while(true){
        if(sNode->key == k)return;
        if(sNode->key > k){
            if(sNode->left == nullptr){
                sNode->left = new Node(k);
                return;
            }
            sNode = sNode->left;
        } else {
            if(sNode->right == nullptr){
                sNode->right = new Node(k);
                return;
            }
            sNode = sNode->right;
        }
    }
}

Node * STree::SearchNode(int n){
    if(root == nullptr || root->key == n)return root;
    Node *sNode = root;
    while(sNode != nullptr && sNode->key != n){
        if(n > sNode->key){
            sNode = sNode->right;
        } else {
            sNode = sNode->left;
        }
    }
    return sNode;
}

void STree::DelNode(int key) {
    Node *parent = nullptr;
    Node *del = root;
    //find both nodes
    while(del != nullptr && del->key != key){
        parent = del;
        if(key < del->key){
            del = del->left;
        } else {
            del = del->right;
        }
    }
    if(del == nullptr)return;
    //del node is a leaf
    if(del->left == nullptr && del->right == nullptr){
        if(parent != nullptr){
            if(parent->left == del) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else {
            root = nullptr;
        }
        delete del;
        return;
    }
    //two children
    if(del->left != nullptr && del->right != nullptr){
        Node *replace1 = del;       //temporary parent
        Node *replace2 = del->left; //temporary child
        //find nearest candidate
        while(replace2->right != nullptr){
            replace1 = replace2;
            replace2 = replace1->right;
        }
        //replacing
        del->key = replace2->key;
        if(replace1 == del){        //case temp parent == del
            del->left = replace2->left;
        } else {                    //general case
            replace1->right = replace2->left;
        }
        delete replace2;
        return;
    }
    //just one child
    Node *replace = del->right;
    if(del->left != nullptr){
        replace = del->left;
    }
    del->key = replace->key;
    del->left = replace->left;
    del->right = replace->right;
    delete replace;
}


AVL::AVL(int *a, int size) {
    if(size == 0){
        root == nullptr;
        return;
    }
    root = new Node(a[0]);
    for(auto i = 1; i < size; i++){
        insert(a[i]);
    }
}

AVL::AVL(int n) : STree(n) {
    if(n == 0){
        root = nullptr;
        return;
    }
    int key = rand() % 100;
    root = new Node(key);
    for(auto i = 1; i < n; i++){
        key = rand() % 100;
        Add(key);
    }
}
void AVL::insert(int x){
    bool h = false;
    root = bAdd(x, root, h);
}
Node * AVL::bAdd(int x, Node *p, bool &h) {
    Node *p1, *p2;
    if(p == nullptr){
        p = new Node(x, 1, 0, nullptr, nullptr);
        h = true;
        p->UpdateHeight();
        return p;
    } else if(p->key > x){
        p->left = bAdd(x, p->left, h);
        if(h){
            if(p->bal == 1){
                p->bal = 0;
                h = false;
            }
            if(p->bal == 0){
                p->bal = -1;
            } else if(p->bal == -1){
                    p1 = p->left;
                    if(p1->bal == -1){//1xLL
                        p->left = p1->right;
                        p1->right = p;
                        p->bal = 0;
                        p = p1;
                    } else {//LR
                        p2 = p1->right;
                        p1->right = p2->left;
                        p2->left = p1;
                        p->left = p2->right;
                        p2->right = p;
                        if(p2->bal == -1){
                            p->bal = 1;
                        } else {
                            p->bal = 0;
                        }
                        if(p2->bal == 1){
                            p1->bal = -1;
                        } else {
                            p1->bal = 0;
                        }
                        p = p2;
                    }
                    p->bal = 0;
                    h = false;

                }
        }
        p->left->UpdateHeight();
        p->right->UpdateHeight();
        p->UpdateHeight();
        return p;
    } else if(p->key < x){
        p->right = bAdd(x, p->right, h);
        if(h){
            if(p->bal == -1){
                p->bal = 0; h = false;
            } else if(p->bal == 0){
                p->bal = 1;
            } else if(p->bal == 1){
                    p1 = p->right;
                    if(p1->bal == 1){//1xRR
                        p->right = p1->left;
                        p1->left = p;
                        p->bal = 0;
                        p = p1;
                    } else {//RL
                        p2 = p1->left;
                        p1->left = p2->right;
                        p2->right = p1;
                        p->right = p2->left;
                        p2->left = p;
                        if(p2->bal == 1){
                            p->bal = -1;
                        } else {
                            p->bal = 0;
                        }
                        if(p2->bal == -1){
                            p->bal = 1;
                        } else {
                            p1->bal = 0;
                        }
                        p = p2;
                    }
                    p->bal = 0;
                    h = false;

                }
        }
        p->left->UpdateHeight();
        p->right->UpdateHeight();
        p->UpdateHeight();
        return p;
    }
}

void AVL::Del(int key) {
    root = RecDel(root, key);
}

Node *AVL::DelTmp(Node *q) {//when we have found substitution
    if(q->left == nullptr){ //for del element we should delete this substitution too
        return q->right;
    }
    q->left = DelTmp(q->left);
    return Balance(q);
}

Node *AVL::RecAdd(Node *q, int key) {
    if(q == nullptr){
        return new Node(key);
    }
    if(key < q->key){
        q->left = RecAdd(q->left, key);
    } else {
        q->right = RecAdd(q->right, key);
    }
    return Balance(q);
}

Node *AVL::RecDel(Node *q, int key) {
    if(q == nullptr){
        return nullptr;
    }

    if(key < q->key){
        q->left = RecDel(q->left, key);
    } else if(key > q->key){
        q->right = RecDel(q->right, key);
    } else {
        Node *l = q->left;
        Node *r = q->right;
        delete q;

        if(r == nullptr)return l;
        Node *tmp = r;
        while(tmp->left != nullptr){
            tmp = tmp->left;
        }
        tmp->right = DelTmp(r);
        tmp->left = l;
        return Balance(tmp);
    }
    return Balance(q);
}

void AVL::balanceL(Node *p, bool &h){
    Node *p1, *p2;
    int b1, b2;
    switch (p->bal){
        case -1:
            p->bal = 0;
            break;
        case 0:
            p->bal = 1;
            h = false;
            break;
        case 1:
            p1 = p->right;
            b1 = p1->bal;
            if(b1 >= 0){//1xRR
                p->right = p1->left;
                p1->left = p;
                if(b1 == 0){
                    p->bal = 1;
                    p1->bal = -1;
                    h = false;
                } else {
                    p->bal = 0;
                    p1->bal = 0;
                }
                p = p1;
            } else {//2xRL
                p2 = p1->left;
                b2 = p2->bal;
                p1->left = p2->right;
                p2->right = p1;
                p->right = p2->left;
                p2->left = p;
                if(b2 == 1){
                    p->bal = -1;
                } else {
                    p->bal = 0;
                }
                if(b2 == -1){
                    p1->bal = -1;
                } else {
                    p1->bal = 0;
                }
                p = p2; p2->bal = 0;
            }
            break;
    }
}
void AVL::balanceR(Node *p, bool &h){
    Node *p1, *p2;
    int b1, b2;
    switch (p->bal) {
        case 1:
            p->bal = 0;
            break;
        case 0:
            p->bal = -1; h = false;
            break;
        case -1:
            p1 = p1->left;
            b1 = p1->bal;
            if(b1 <= 0){//1xLL
                p->left = p1->right;
                p1->right = p;
                if(b1 == 0){
                    p->bal = -1;
                    p1->bal = 1;
                    h = false;
                } else {
                    p->bal = 0;
                    p1->bal = 0;
                }
                p = p1;
            } else {//2xLR
                p2 = p1->right;
                b2 = p2->bal;
                p1->right = p2->left;
                p2->left = p1;
                p->left = p2->right;
                p2->right = p;
                if(b2 == -1){
                    p->bal = 1;
                } else {
                    p->bal = 0;
                }
                if(b2 == 1){
                    p1->bal = -1;
                } else {
                    p1->bal = 0;
                }
                p = p2;
                p2->bal = 0;
            }
            break;
    }
}

//Node *AVL::delete1(int x, Node *p, bool &h){
//    Node *q;
//    if(p == nullptr)return nullptr;
//    while(p->right != nullptr)
//
//    if(p->key > x){
//        delete1(x, p->right, h);
//        if(h){
//            balanceR(p, h);
//        }
//    } else {
//        q = p;
//        if(q->right == nullptr){
//            p = q->left;
//            h = true;
//        } else if(q->left == nullptr){
//            p = q->right;
//            h = true;
//        } else {
//            del1(q->left, h);
//            if(h)balanceL(p, h);
//        }
//        delete q;
//    }
//}
//
//Node *AVL::del1(Node *r, Node *q, bool &h){
//    if(r->right != nullptr){
//        del1(r->right, h);
//        if(h)balanceR(r, h);
//    } else {
//        q = r;
//        r = r->left;
//        h = true;
//    }
//}