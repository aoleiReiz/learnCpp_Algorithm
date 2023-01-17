//
// Created by aolei.bao on 1/13/2023.
//

#include "MidLast8.h"

bool MidLast8::oneEdit(string stringOne, string stringTwo) {
    int oneLength = stringOne.length();
    int twoLength = stringTwo.length();
    if (oneLength - twoLength > 1 || oneLength - twoLength < -1){
        return false;
    }
    int indexOne = 0, indexTwo = 0;
    bool madeEdit = false;
    while (indexOne < oneLength && indexTwo < twoLength){
        if (stringOne[indexOne] != stringTwo[indexTwo]){
            if (madeEdit){
                return false;
            }
            madeEdit = true;
            if (oneLength > twoLength){
                indexOne ++;
            } else if (twoLength > oneLength){
                indexTwo ++;
            }else{
                indexOne ++;
                indexTwo ++;
            }
        }else{
            indexOne ++;
            indexTwo ++;
        }
    }
    return true;
}

bool MidLast8::symmetricalTree(BinaryTree *tree) {
    return symmetricalTreeHelper(tree, tree);
}

bool MidLast8::symmetricalTreeHelper(BinaryTree *tree1, BinaryTree *tree2) {
    if (tree1 == nullptr && tree2 == nullptr){
        return true;
    }
    else if(tree1 && tree2){
        return tree2->value == tree1->value && symmetricalTreeHelper(tree1->left, tree2->right) &&
                symmetricalTreeHelper(tree1->right, tree2->left);
    }
    return false;
}

LinkedList *MidLast8::mergingLinkedLists(LinkedList *linkedListOne, LinkedList *linkedListTwo) {
    unordered_set<LinkedList*>setOne;
    unordered_set<LinkedList*>setTwo;
    LinkedList *ptrOne = linkedListOne;
    LinkedList *ptrTwo = linkedListTwo;
    while (ptrOne && ptrTwo){
        auto it1 = setTwo.find(ptrOne);
        if (it1 != setTwo.end()){
            return *it1;
        }
        auto it2 = setOne.find(ptrTwo);
        if (it2 != setOne.end()){
            return *it2;
        }
        setOne.insert(ptrOne);
        setTwo.insert(ptrTwo);
        ptrOne ++;
        ptrTwo ++;
    }
    return nullptr;
}
