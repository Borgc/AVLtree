//
// Created by SLAVA on 21.06.2021.#
#include "library.h"

int main() {
srand(31029);
//STree T(10);
//T.PrintTree(T.GetRoot(), 0);
//int *a = new int[10];
//T.LNR(a);
//for(int i = 0; i < 10; i++){
//    std::cout << a[i] << ' ';
//}
//    delete [] a;
//int a;
//std::cin >> a;
//T.DelNode(a);
//T.PrintTree(T.GetRoot(), 0);

//STree A(10);
//A.PrintTree(A.GetRoot(), 0);
//Node * FNode = A.SearchNode(2);
//if(FNode != nullptr)std::cout << FNode->GetKey();
//std::cout << '\n';
//std::list <Node *> list;
//A.LevelTrav(list);
//for(auto it : list){
//    std::cout << it->GetKey() << ' ';
//}

//int a[4];
//a[0] = 4;
//a[1] = 3;
//a[2] = 2;
//a[3] = 1;
//AVL T(a, 4);
//T.PrintTree(T.GetRoot(), 0);
//Node *sNode = T.SearchNode(2);
//std::cout << sNode->GetKey();
//T.PrintTree(T.GetRoot(), 0);
AVL T(0);
//T.insert(4);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";
//T.insert(5);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";
//T.insert(7);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";
//T.insert(2);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";
//T.insert(1);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";
//T.insert(3);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";
//T.insert(6);
//T.PrintTree(T.GetRoot(), 0);
//std::cout << "<------------------------------->\n";

T.insert(5);
T.insert(3);
T.insert(8);
T.insert(2);
T.insert(4);
T.insert(7);
T.insert(10);
T.insert(1);
T.insert(6);
T.insert(9);
T.insert(11);

T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(4);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(8);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(6);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(5);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(2);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(1);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
T.Del(7);
T.PrintTree(T.GetRoot(), 0);
std::cout << "<------------------------------->\n";
return 0;
}
