//
// Created by aolei.bao on 1/13/2023.
//

#ifndef LEARNCPP_ALGORITHM_MIDLAST8_H
#define LEARNCPP_ALGORITHM_MIDLAST8_H
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) {
        this->value = value;
    }
};


class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) {
        this->value = value;
    }
};


class MidLast8 {
public:
    bool oneEdit(string stringOne, string stringTwo);
    bool symmetricalTree(BinaryTree* tree);
    bool symmetricalTreeHelper(BinaryTree* tree1, BinaryTree* tree2);
    LinkedList* mergingLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo);
};


#endif //LEARNCPP_ALGORITHM_MIDLAST8_H
